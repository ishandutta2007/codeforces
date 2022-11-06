#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
vector<int>e[100010];
int l[100010],r[100010];
int n;

LL dp[100010][2];

void dfs(int x, int fa) {
    dp[x][0] = dp[x][1] = 0;
    for (auto &t : e[x]) {
        if (t != fa) {
            dfs(t, x);
            dp[x][0] += max(abs(l[x] - l[t]) + dp[t][0], abs(l[x] - r[t]) + dp[t][1]);
            dp[x][1] += max(abs(r[x] - l[t]) + dp[t][0], abs(r[x] - r[t]) + dp[t][1]);
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            e[i].clear();
            scanf("%d%d",&l[i],&r[i]);
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        printf("%lld\n",max(dp[1][0],dp[1][1]));
    }
}