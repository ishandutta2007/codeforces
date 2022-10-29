#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e9 + 1;
const int N = 1005;
mt19937 rng(time(0));

int T, n, a[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        int ans = 0;
        rep(l, 1, n) rep(r, l, n) {
            ans += r - l + 1;
            rep(i, l, r) ans += (a[i] == 0);
        }
        cout << ans << endl;
    }
    return 0;
}