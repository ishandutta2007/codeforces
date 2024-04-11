#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int n,q,counter;
int a[100013];
int num[100013];
vector<int> adj[100013];
vector<int> where[100013];
vector<int> factors[100013];
int ans[100013];
int visited[100013];
map<int,stack<int> > seen;

void renumber(int x) {
    visited[x] = 1;
    num[x] = counter;
    counter+=1;
    int tmp = a[x];
    for (int i=2;i*i<=tmp;i++) {
        if (tmp%i==0) factors[x].push_back(i);
        while (tmp%i==0) tmp/=i;
    }
    if (tmp>1) factors[x].push_back(tmp);
    for (int i=0;i<adj[x].size();i++) if (!visited[adj[x][i]]) renumber(adj[x][i]);
}

void dfs(int x) {
    visited[x] = 1;
    int cur = -1;
    for (int i=0;i<factors[x].size();i++) {
        if (seen[factors[x][i]].size()>0) {
            int poss = seen[factors[x][i]].top();
            if (cur==-1 || num[poss]>num[cur-1]) cur = poss+1;
        }
    }
    for (int i=0;i<where[x].size();i++) ans[where[x][i]] = cur;
    for (int i=0;i<factors[x].size();i++) seen[factors[x][i]].push(x);
    for (int i=0;i<adj[x].size();i++) if (!visited[adj[x][i]]) dfs(adj[x][i]);
    for (int i=0;i<factors[x].size();i++) seen[factors[x][i]].pop();
}

int main() {
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=1;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        x-=1; y-=1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    counter = 0;
    renumber(0);
    int last = 0;
    int cnt = 0;
    for (int i=0;i<q;i++) {
        int t;
        scanf("%d",&t);
        if (t==1) {
            int v;
            scanf("%d",&v);
            v-=1;
            cnt+=1;
            where[v].push_back(i-last);
        } else {
            for (int j=0;j<n;j++) visited[j] = 0;
            dfs(0);
            for (int j=0;j<cnt;j++) printf("%d\n",ans[j]);
            for (int j=0;j<n;j++) where[j].clear();
            last = i+1;
            cnt = 0;
            int v,w;
            scanf("%d%d",&v,&w);
            v-=1;
            a[v] = w;
            factors[v].clear();
            int tmp = a[v];
            for (int i=2;i*i<=tmp;i++) {
                if (tmp%i==0) factors[v].push_back(i);
                while (tmp%i==0) tmp/=i;
            }
            if (tmp>1) factors[v].push_back(tmp);
        }
    }
    for (int j=0;j<n;j++) visited[j] = 0;
    dfs(0);
    for (int j=0;j<cnt;j++) printf("%d\n",ans[j]);

    return 0;
}