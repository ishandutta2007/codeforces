#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
int P = 998244353;
const int INF = 1e9 + 1;
const int N = 1005;
mt19937 rng(time(0));

int T, n, a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    rep(cas, 1, T) {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        rep(i, 1, n) cin >> b[i];
        rep(i, 2, n) if (abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]) < abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1])) swap(a[i], b[i]);
        LL ans = 0;
        rep(i, 2, n) ans += abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]);
        cout << ans << "\n";
    }
    return 0;
}