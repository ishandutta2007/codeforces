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
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[abs(x)]++;
        }
        int ans = 0;
        for (auto it : cnt) {
            if (it.first != 0) ans += min(2ll, it.second);
            else ans += min(1ll, it.second);
        }
        cout << ans << '\n';
    }
}