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
        int cnt = 0;
        for (auto &it : a) {
            cin >> it;
            while (it % 2 == 0) {
                it /= 2;
                cnt++;
            }
        }
        sort(all(a));
        for (int i = 0; i < cnt; i++) {
            a.back() *= 2;
        }
        int ans = 0;
        for (auto it : a) {
            ans += it;
        }
        cout << ans << '\n';
    }
}