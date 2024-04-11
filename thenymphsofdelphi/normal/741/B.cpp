#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
int n, m, w, u, v, beauty[1010], beast[1010],
par[1010], dp[2010][1010], cnt = 0;
vector<int> connected_component[1010];
vector<pair <pair <int, int>, int> > hoses;
 
int find(int a) {
    return (par[a] < 0 ? a : par[a] = find(par[a]));
}
 
int main() {
    memset(par, -1, sizeof(par));
    scanf("%d%d%d", &n, &m, &w);
    for(int i = 0; i < n; i++) scanf("%d", &beast[i]);
    for(int i = 0; i < n; i++) scanf("%d", &beauty[i]);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v); u--, v--;
        int p1 = find(u), p2 = find(v);
        if(p1 == p2) continue;
        if(par[p1] < par[p2]) par[p1] += par[p2], par[p2] = p1;
        else par[p2] += par[p1], par[p1] = p2;
    }
    for(int i = 0; i < n; i++) {
        int p = find(i);
        connected_component[p].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        if(not connected_component[i].size()) continue;
        int a = 0, b = 0;
        for(int j : connected_component[i]) {
            a += beauty[j], b += beast[j];
            hoses.push_back({{beauty[j], beast[j]}, 0});
        }
        hoses.push_back({{a, b}, 1});
    }
    memset(dp, -63, sizeof(dp));
    dp[0][0] = 0; int last = 0;
    for(int i = 1; i <= hoses.size(); i++) {
        int a = hoses[i-1].fi.fi, b = hoses[i-1].fi.se, state = hoses[i-1].se;
        for(int j = 0; j <= w; j++) {
            dp[i][j] = dp[i-1][j];
            if(b <= j && dp[last][j-b] >= 0) dp[i][j] = max(dp[i][j], dp[last][j-b] + a);
        }
        if(state) last = i;
    }
    int ans = 0;
    for(int j = 0; j <= w; j++) ans = max(ans, dp[hoses.size()][j]);
    printf("%d\n", ans);
}