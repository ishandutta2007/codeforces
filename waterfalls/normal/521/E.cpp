#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define A first
#define B second

pair<int,int> MP(int a, int b) { return make_pair(min(a,b),max(a,b)); }

int n,m,counter;
vector<int> adj[200013];
vector<vector<pair<int,int> > > bcc;
vector<vector<int> > has;
int num[200013];
int low[200013];
stack<pair<int,int> > s;

void dfs(int x, int p, int start) {
    low[x] = num[x] = counter++;
    int child = 0;
    for (int j=0;j<adj[x].size();j++) {
        int i = adj[x][j];
        if (!num[i]) {
            child+=1;
            s.push(MP(x,i));
            dfs(i,x,start);
            low[x] = min(low[x],low[i]);
            if (low[i]>=num[x] || (num[x]==start && child>1)) {
                bcc.push_back(vector<pair<int,int> >());
                while (s.top()!=MP(x,i)) {
                    bcc[bcc.size()-1].push_back(s.top());
                    s.pop();
                }
                bcc[bcc.size()-1].push_back(s.top());
                s.pop();
            }
        } else if (i!=p && num[i]<num[x]) low[x] = min(low[x],num[i]), s.push(MP(x,i));
    }
}

vector<int> cyc;
bool in[200013];
bool dfscyc(int x, int start) {
    num[x] = 1;
    if (cyc.size()>2 && x==start) return true;
    cyc.push_back(x);
    for (int i=0;i<adj[x].size();i++) {
        if (!num[adj[x][i]] || (adj[x][i]==start && cyc.size()>2)) {
            if (dfscyc(adj[x][i],start)) return true;
        }
    }
    cyc.pop_back();
    return false;
}

vector<int> thr;
int dfsfin(int x, int start) {
    num[x] = 1;
    thr.push_back(x);
    if (in[x] && x!=start) return x;
    for (int i=0;i<adj[x].size();i++) if (!num[adj[x][i]]) {
        int pos = dfsfin(adj[x][i],start);
        if (pos) return pos;
    }
    thr.pop_back();
    return 0;
}

vector<int> one;
vector<int> two;
bool check(int x) {
    for (int i=0;i<has[x].size();i++) {
        adj[has[x][i]].clear();
        num[has[x][i]] = 0;
        in[has[x][i]] = 0;
    }
    for (int i=0;i<bcc[x].size();i++) {
        adj[bcc[x][i].A].push_back(bcc[x][i].B);
        adj[bcc[x][i].B].push_back(bcc[x][i].A);
    }
    cyc.clear();
    if (!dfscyc(has[x][0],has[x][0])) return false;
    for (int i=0;i<cyc.size();i++) {
        in[cyc[i]] = 1;
        int a = cyc[i];
        int b = cyc[(i+1)%cyc.size()];
        adj[a].erase(find(adj[a].begin(),adj[a].end(),b));
        adj[b].erase(find(adj[b].begin(),adj[b].end(),a));
    }
    int found = 0;
    for (int i=0;i<cyc.size();i++) if (adj[cyc[i]].size()>0) found = 1;
    if (!found) return false;
    int s = 0;
    int e;
    for (int i=0;i<has[x].size();i++) num[has[x][i]] = 0;
    for (int i=0;i<cyc.size();i++) {
        if (adj[cyc[i]].size()>0) s = cyc[i];
        if (s) {
            e = dfsfin(s,s);
            break;
        }
    }
    int a = 0;
    for (int i=0;i<cyc.size();i++) if (cyc[i]==s) a = i;
    int b = 0;
    for (int i=0;i<cyc.size();i++) if (cyc[i]==e) b = i;
    for (int i=a;i!=b;i = (i+1)%cyc.size()) one.push_back(cyc[i]);
    one.push_back(e);
    for (int i=b;i!=a;i = (i+1)%cyc.size()) two.push_back(cyc[i]);
    two.push_back(s);
    reverse(two.begin(),two.end());
    return true;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    counter = 1;
    for (int i=1;i<=n;i++) if (!num[i]) dfs(i,-1,counter);
    for (int i=0;i<bcc.size();i++) {
        has.push_back(vector<int>());
        for (int j=0;j<bcc[i].size();j++) {
            has[has.size()-1].push_back(bcc[i][j].A);
            has[has.size()-1].push_back(bcc[i][j].B);
        }
    }
    for (int i=1;i<=n;i++) adj[i].clear(), num[i] = 0;
    int found = 0;
    for (int i=0;i<bcc.size() && !found;i++) {
        found = check(i);
    }
    if (found) {
        printf("YES\n");
        printf("%d",one.size());
        for (int i=0;i<one.size();i++) printf(" %d",one[i]);
        printf("\n");
        printf("%d",two.size());
        for (int i=0;i<two.size();i++) printf(" %d",two[i]);
        printf("\n");
        printf("%d",thr.size());
        for (int i=0;i<thr.size();i++) printf(" %d",thr[i]);
        printf("\n");
    } else printf("NO\n");

    return 0;
}