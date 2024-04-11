#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 998244353;
const int INF = 1e9 + 5;
const int N = 3e5 + 5;
mt19937 rng(time(0));

int T, n;
LL a[N];

LL f(int x) {
    LL n1 = 0, n2 = 0, ans;
    rep(i, 1, n) n1 += (x - a[i]) % 2, n2 += (x - a[i]) / 2;
    if (n2 > n1) {
        LL y = (n2 - n1) / 3;
        n2 -= y, n1 += y + y;
        if (n2 >= n1 + 2)
            n2--, n1 += 2;
    }
    ans = max(n1 * 2 - 1, n2 * 2);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    rep(cas, 1, T) {
        cin >> n;
        LL x = 0;
        rep(i, 1, n) cin >> a[i], x = max(x, a[i]);
        cout << min(f(x), f(x + 1)) << "\n";
    }
    return 0;
}