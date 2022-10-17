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
            int n, k;
            cin >> n >> k;
            if (k % 2 == 1) {
                cout << "YES\n";
                for (int i = 1; i <= n; i += 2) {
                    cout << i << ' ' << i + 1 << '\n';
                }
            } else if (k % 4 == 2) {
                cout << "YES\n";
                for (int i = 2; i <= n; i += 2) {
                    if (i % 4 == 0) {
                        cout << i - 1 << ' ' << i << '\n';
                    } else {
                        cout << i << ' ' << i - 1 << '\n';
                    }
                }
            } else {
                cout << "NO\n";
            }
        }
        return 0;
    }