#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5;
bool v[maxn << 1];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        bool ans = true;
        memset(v, false, sizeof(v));
        int k; cin >> k; while (k--) {
            int x; cin >> x;
            if (x > 0) {
                if (v[x]) ans = false;
                v[x + maxn] = true;
            } else {
                x = -x;
                if (v[x + maxn]) ans = false;
                v[x] = true;
            }
        }
        if (ans) return cout << "YES\n", 0;
    }
    cout << "NO\n";
    return 0;
}