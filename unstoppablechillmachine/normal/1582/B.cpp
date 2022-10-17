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
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                cnt0++;
            } else if (x == 1) {
                cnt1++;
            }
        }
        cout << (1ll << cnt0) * cnt1 << endl;
    }
}