#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S secondond
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
        bool all_ones = true;
        int sum = 0;
        for (auto &x : a) {
            cin >> x;
        }
        for (int i = 1; i + 1 < n; i++) {
            if (a[i] > 1) {
                all_ones = false;
            }
            sum += (a[i] + 1) / 2;
        }
        if ((n == 3 && a[1] % 2 == 1) || all_ones) {
            cout << -1 << '\n';
        } else {
            cout << sum << '\n';
        }
    }
}