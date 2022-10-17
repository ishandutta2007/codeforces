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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i] >> a[i];
        }
        int l = 1, r = n + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int cur = 0;
            for (int i = 0; i < n; i++) {
                if (cur <= a[i] && cur + 1 + b[i] >= mid) {
                    cur++;
                }
            }
            if (cur >= mid) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << '\n';
    }
}