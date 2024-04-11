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
        int n, m;
        cin >> n >> m;
        map<int, pair<int, int>> have;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (!have.count(x)) {
                have[x] = {i, i};
            } else {
                have[x].second = i;
            }
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if (have.count(a) && have.count(b) && have[a].first <= have[b].second) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}