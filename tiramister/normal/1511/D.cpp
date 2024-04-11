#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    {
        auto vis = vector(k, vector(k, false));
        auto dfs = [&](auto&& f, int v) -> void {
            for (int u = 0; u < k; ++u) {
                if (vis[v][u]) continue;
                vis[v][u] = true;
                f(f, u);
            }
            s.push_back('a' + v);
        };
        dfs(dfs, 0);
        s.pop_back();
    }

    int m = s.length();
    for (int i = 0; i < n; ++i) cout << s[i % m];
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}