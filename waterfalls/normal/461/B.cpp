#include <cstdio>
#include <vector>

using namespace std;

int n,root;
vector<vector<int> > adj;
int color[100000];
int visited[100000];
int MOD = 1000000007;

pair<int,int> dfs(int x) {
    visited[x] = 1;
    int zero = 1-color[x];
    int one = color[x];
    for (int n=0;n<adj[x].size();n++) {
        int i = adj[x][n];
        if (visited[i]) continue;
        int pZero = zero;
        int pOne = one;
        zero = one = 0;
        pair<int,int> vals = dfs(i);
        int nZero = vals.first;
        int nOne = vals.second;
        zero = (zero+(long long) pZero*nOne)%MOD;
        one = (one+(long long) pOne*nOne)%MOD;
        zero = (zero+(long long) pZero*nZero)%MOD;
        one = (one+(long long) pOne*nZero)%MOD;
        one = (one+(long long) pZero*nOne)%MOD;
    }
    return make_pair(zero,one);
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) adj.push_back(vector<int>());
    for (int i=1;i<n;i++) {
        int p;
        scanf("%d",&p);
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    for (int i=0;i<n;i++) scanf("%d",&color[i]);
    for (int i=0;i<n;i++) if (color[i]) root = i;
    for (int i=0;i<n;i++) visited[i] = 0;
    printf("%d\n",dfs(root).second);

    return 0;
}