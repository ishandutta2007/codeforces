#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        vector<vector<int>> g(n + 1);
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p >> a[i] >> b[i];
            g[p].push_back(i);
        }
        vector<int> have;
        vector<int> answer(n + 1);
        function<void(int, int, int)> dfs = [&](int v, int sum_a, int sum_b) {
            sum_a += a[v];
            sum_b += b[v];
            have.push_back(sum_b);
            answer[v] = upper_bound(have.begin(), have.end(), sum_a) - have.begin();
            for (auto u : g[v]) {
                dfs(u, sum_a, sum_b);
            }
            have.pop_back();
        };
        dfs(1, 0, 0);
        for (int i = 2; i <= n; i++) {
            cout << answer[i] - 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}