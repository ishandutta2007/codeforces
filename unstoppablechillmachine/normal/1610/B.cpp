#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it : a) {
            cin >> it;
        }
        bool ok = true;
        pair<int, int> cands;
        for (int i = 0; i < n; i++) {
            if (a[i] != a[n - i - 1]) {
                ok = false;
                cands = {a[i], a[n - i - 1]};
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            auto solve = [&](int x) {
                int l = 0, r = n - 1;
                while (r > l) {
                    if (a[l] != a[r]) {
                        if (a[l] == x) {
                            l++;
                        } else if (a[r] == x) {
                            r--;
                        } else {
                            return false;
                        }
                    } else {
                        l++;
                        r--;
                    }
                }
                return true;
            };
            if (solve(cands.first) || solve(cands.second)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}