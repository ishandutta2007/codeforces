#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 105;
mt19937 rng(time(0));

int T, n, d;
double a[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        rep(i, 1, n - 1) rep(j, i + 1, n) {
            double d = (a[j] - a[i]) / (j - i), a1 = a[i] - (i - 1) * d;
            int cnt = 0;
            rep(k, 1, n) if (abs(a1 + (k - 1) * d - a[k]) < 1e-7) cnt++;
            ans = max(ans, cnt);
        }
        cout << n - ans << endl;
    }
    return 0;
}