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

int T, n, x, a[N];

int main() {
    cin >> T;
    while (T--) {
        memset(a, 0, sizeof a);
        cin >> n;
        rep(i, 1, n) scanf("%d", &x), a[abs(x)]++;
        int ans = min(a[0], 1);
        rep(i, 1, 100) ans += min(a[i], 2);
        cout << ans << endl;
    }
    return 0;
}