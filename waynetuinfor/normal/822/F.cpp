// test
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
vector<pair<int, int>> G[maxn];

void dfs(int, int, double);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(make_pair(b, i)); G[b].push_back(make_pair(a, i));
    }
    cout << n - 1 << endl;
    dfs(1, 0, 0.0);
    return 0;
}

void dfs(int x, int fa, double d) {
    int deg = 0, ind = 0;
    for (auto u : G[x]) ++deg;
    for (auto u : G[x]) if (u.first != fa) {
        cout << 1 << ' ' << u.second << ' ';
        ++ind; double t = d + (double)ind * (double)2 / (double)deg;
        while (t > 2.0) t -= 2.0;
        if (t > 1.0) cout << x << ' ' << u.first << ' ' << fixed << setprecision(10) << t - 1.0 << endl;
        else cout << u.first << ' ' << x << ' ' << fixed << setprecision(10) << t << endl;
        dfs(u.first, x, t >= 1 ? t - 1 : t + 1);
    }
}