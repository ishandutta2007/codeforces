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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n <= 2) {
            cout << 0 << '\n';
            continue;
        }
        int ans = n - 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pair<int, int> d = {a[j] - a[i], j - i};
                int sum = n;
                for (int k = 0; k < n; k++) {
                    if (a[k] * d.second == a[i] * d.second + d.first * (k - i)) {
                        sum--;
                    }
                }
                ans = min(ans, sum);
            }
        }
        cout << ans << '\n';
    }
}