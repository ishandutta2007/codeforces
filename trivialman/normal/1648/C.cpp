#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 998244353;
const int INF = 1e5 + 5;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, m;
int s[N], t[N], tr[N];
LL fac[N], ifac[N];

int pw(LL x, LL n) {
    LL res = 1;
    for (; n; n >>= 1, x = x * x % P)
        if (n & 1)
            res = res * x % P;
    return res;
}

void add(int x, int v) {
    for (; x <= 200000; x += x & -x)
        tr[x] += v;
}
int get(int x) {
    int res = 0;
    for (; x; x -= x & -x)
        res += tr[x];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    fac[0] = 1;
    rep(i, 1, N - 1) fac[i] = fac[i - 1] * i % P;
    ifac[N - 1] = pw(fac[N - 1], P - 2);
    rrep(i, N - 2, 0) ifac[i] = ifac[i + 1] * (i + 1) % P;
    cerr << "ifac[0]=" << ifac[0] << endl;

    cin >> n >> m;
    rep(i, 1, n) cin >> s[i], add(s[i], 1);
    rep(i, 1, m) cin >> t[i];
    LL mul = 1;
    rep(i, 1, 200000) mul = mul * ifac[get(i) - get(i - 1)] % P;

    LL ans = 0;
    rep(i, 1, min(m, n)) {
        int num = get(t[i] - 1 + (n < m && i == n));
        ans = (ans + 1ll * num * fac[n - i] % P * mul % P) % P;
        //cerr << i << " " << num << " " << mul << " " << ans << endl;
        int nt = get(t[i]) - get(t[i] - 1);
        if (nt == 0)
            break;
        else {
            mul = mul * fac[nt] % P * ifac[nt - 1] % P;
            add(t[i], -1);
        }
    }
    cout << ans;
    return 0;
}