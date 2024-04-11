#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 105;
mt19937 rng(time(0));

int T, n, x, a[20];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        LL mul = 1, res = 0;
        rep(i, 1, n) {
            cin >> x;
            while (x % 2 == 0)
                x /= 2, mul *= 2;
            a[i] = x;
        }
        sort(a + 1, a + n + 1);
        rep(i, 1, n - 1) res += a[i];
        res += a[n] * mul;
        cout << res << endl;
    }
    return 0;
}