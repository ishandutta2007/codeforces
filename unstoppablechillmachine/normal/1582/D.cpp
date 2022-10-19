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
    auto lcm = [](int a, int b) {
        return a * b / gcd(a, b);
    };

    while (T--) {
        int n;
        cin >> n;
        if (n & 1) {
            vector<int> a(n);
            for (auto &x : a) {
                cin >> x;
            }
            vector<int> ans(n);
            ans[0] = 1;
            int cur = a[0];
            for (int i = 1; i + 1 < n; i++) {
                if (a[i] * cur > 0) {
                    ans[i] = -1;
                } else {
                    ans[i] = 1;
                }
                cur += ans[i] * a[i];
            }
            if (cur == 0) {
                cur += ans[n - 2] * a[n - 2];
                ans[n - 2] *= 2;
            }
            int g = lcm(cur, a.back());
            int coef = g / cur;
            ans.back() = -g / a.back();
            for (int i = 0; i + 1 < n; i++) {
                ans[i] *= coef;
            }
            for (auto it : ans) {
                cout << it << ' ';
            }
            cout << '\n';
        } else {
            vector<int> a(n);
            for (auto &x : a) {
                cin >> x;
            }
            vector<int> ans(n);
            for (int i = 0; i < n; i += 2) {
                int g = lcm(a[i], a[i + 1]);
                ans[i] = g / a[i];
                ans[i + 1] = -g / a[i + 1];
            }
            for (auto it : ans) {
                cout << it << ' ';
            }
            cout << '\n';
        }

    }
}