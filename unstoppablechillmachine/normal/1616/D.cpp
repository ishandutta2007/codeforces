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
        int x;
        cin >> x;
        for (auto &it : a) {
            it -= x;
        }
        int ans = n;
        vector<bool> del(n);
        int min_suf = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || del[i - 1]) {
                min_suf = a[i];
                continue;
            }
            if (a[i] + min_suf < 0) {
                ans--;
                del[i] = true;
                min_suf = 0;
            } else {
                min_suf = min(a[i], a[i] + min_suf);
            }
        }
        cout << ans << '\n';
    }
}