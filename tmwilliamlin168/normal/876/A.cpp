#include <bits/stdc++.h>

#define ll long long
using namespace std;



int main() {
#ifdef __APPLE__
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int cur = 0;
    vector<vector<int>> g = {{10000, a, b},
                             {a, 10000, c},
                             {b, c, 10000}};
    int ans = 0;
    while (--n) {
        int x = 0;
        for (int i = 0; i < 3; ++i) {
            if (g[cur][i] < g[cur][x])
                x = i;
        }
        ans += g[cur][x];
        cur = x;
    }
    printf("%d", ans);
    return 0;
}