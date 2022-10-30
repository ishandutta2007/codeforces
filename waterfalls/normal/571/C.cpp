#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m;
vector<int> has[400013];
int val[400013];
vector<pair<int,int> > show[400013];
int done[400013];
vector<pair<int,int> > adj[400013];
int visited[400013];
int go[400013];

int found[400013];
int p[400013];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) {
    found[find(b)]|=found[find(a)];
    p[find(a)] = find(b);
}

void dfs(int x) {
    visited[x] = 1;
    for (pair<int,int> i: adj[x]) if (!done[i.A]) {
        done[i.A] = 1;
        val[i.B/2] = i.B%2;
        dfs(i.A);
    }
}

vector<int> path;
bool findcyc(int x, int s, int pp=-1) {
    visited[x] = 1;
    path.push_back(x);
    for (pair<int,int> i: adj[x]) {
        if (i.A==pp) pp = -1;
        else if (i.A==s || (!visited[i.A] && findcyc(i.A,s,x))) {
            done[i.A] = 1;
            val[i.B/2] = i.B%2;
            return true;
        }
    }
    path.pop_back();
    return false;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) val[i] = 2;
    for (int i=0;i<n;i++) {
        int k;
        scanf("%d",&k);
        if (k==0) return printf("NO\n"), 0;
        for (int j=0;j<k;j++) {
            int x;
            scanf("%d",&x);
            if (x<0) x = (-x-1)*2;
            else x = (x-1)*2+1;
            show[x/2].push_back(MP(i,x));
        }
    }
    for (int i=0;i<n;i++) p[i] = i, go[i] = -1;
    for (int i=0;i<m;i++) {
        if (show[i].size()==0) continue;
        if (show[i].size()==1) {
            val[i] = show[i][0].B%2;
            done[show[i][0].A] = 1;
        } else {
            if (show[i][0].B==show[i][1].B) {
                val[i] = show[i][0].B%2;
                done[show[i][0].A] = 1;
                done[show[i][1].A] = 1;
            } else {
                if (find(show[i][0].A)==find(show[i][1].A)) {
                    if (!found[find(show[i][0].A)]) {
                        go[show[i][0].A] = 1;
                        adj[show[i][0].A].push_back(show[i][1]);
                        adj[show[i][1].A].push_back(show[i][0]);
                        found[find(show[i][0].A)] = 1;
                    }
                } else {
                    merge(show[i][0].A,show[i][1].A);
                    adj[show[i][0].A].push_back(show[i][1]);
                    adj[show[i][1].A].push_back(show[i][0]);
                }
            }
        }
    }
    for (int i=0;i<n;i++) {
        if (done[i] && !visited[i]) {
            dfs(i);
        }
    }
    for (int i=0;i<n;i++) if (!done[i] && go[i]!=-1) {
        path.clear();
        findcyc(i,i);
        for (int x: path) dfs(x);
    }
    int ok = 1;
    for (int i=0;i<n;i++) if (!done[i]) ok = 0;
    if (ok) {
        printf("YES\n");
        for (int i=0;i<m;i++) printf("%d",val[i]==2 ? 0 : val[i]);
        printf("\n");
    } else printf("NO\n");

    return 0;
}