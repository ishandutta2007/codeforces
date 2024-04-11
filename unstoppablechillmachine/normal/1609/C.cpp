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

const int N = 2e5 + 10;
const int MX = 1e6 + 10;
int a[N], f[N], f2[N];
bool p[MX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    p[1] = true;
    for (int i = 2; i < MX; i++) {
        if (!p[i]) {
            for (int j = i * i; j < MX; j += i) {
                p[j] = true;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, e;
        cin >> n >> e;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = n; i >= n - e + 1; i--) {
            if (a[i] == 1) {
                f[i] = 1;
                f2[i] = 1;
            } else if (!p[a[i]]) {
                f[i] = 0;
                f2[i] = 1;
            } else {
                f[i] = f2[i] = 0;
            }
        }
        for (int i = n - e; i >= 1; i--) {
            if (a[i] == 1) {
                f[i] = 1 + f[i + e];
                f2[i] = 1 + f2[i + e];
            } else if (!p[a[i]]) {
                f[i] = 0;
                f2[i] = 1 + f[i + e];
            } else {
                f[i] = f2[i] = 0;
            }
        }
        int ans = 0;
        for (int s = 1; s <= n; s++) {
            ans += f2[s] - f[s];
            if (!p[a[s]]) {
                ans--;
            }
            //cerr << s << ' ' << f2[s] << ' ' << f[s] << ' ' << ans << '\n';
        }
        //cerr << '\n';
        cout << ans << '\n';
    }
}