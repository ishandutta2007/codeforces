#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,counter;
vector<int> adj[500013];
int val[500013];
int in[500013];
int out[500013];
vector<int> at[500013];
vector<int> cur[500013];

void dfs(int x, int d=0) {
    in[x] = counter++;
    at[d].push_back(in[x]);
    cur[d].push_back(cur[d].back()^val[x]);
    for (int i: adj[x]) dfs(i,d+1);
    out[x] = counter;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=2;i<=n;i++) {
        int p;
        scanf("%d",&p);
        adj[p].push_back(i);
    }
    for (int i=1;i<=n;i++) {
        char c;
        scanf(" %c",&c);
        val[i] = (1<<((int) c-'a'));
    }
    for (int i=0;i<n;i++) {
        at[i].push_back(0);
        cur[i].push_back(0);
    }
    counter = 1;
    dfs(1);
    for (int q=0;q<m;q++) {
        int v,h;
        scanf("%d%d",&v,&h);
        h-=1;
        auto l = --lower_bound(at[h].begin(),at[h].end(),in[v]);
        auto r = --lower_bound(at[h].begin(),at[h].end(),out[v]);
        if (*r<in[v]) {
            printf("Yes\n");
            continue;
        } else {
            int pos = cur[h][l-at[h].begin()]^cur[h][r-at[h].begin()];
            printf("%s\n",((pos==0 || (pos&(pos-1))==0) ? "Yes" : "No"));
        }
    }

    return 0;
}