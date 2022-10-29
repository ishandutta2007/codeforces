#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
#define ar3 array<int, 3>
typedef long long LL;
const LL P = 998244353;
const int N = (1 << 18) + 5;
const LL INF = 1e18;
const double pi = acos(-1);
mt19937 rng(time(0));

// rk: rank of suffix starting at i; st: sorted suffix index
int n, m, k, tot[N], rk[N], rk1[N], st[N], st1[N], lcp[N];
char s[N], t[N];

inline int RK(int x) { return x <= n ? rk[x] : 0; }

int main() {
    cin >> n, n = 1 << n;
    cin >> (s + 1);
    n = strlen(s + 1) + 1, m = max(n, 128); // max(n, 128) only for strings
    rep(i, 1, n) rk[i] = s[i];

    for (int step = 1; step < n; step <<= 1) {
        memset(tot, 0, sizeof tot);
        rep(i, 1, n)++ tot[RK((i - 1 ^ step) + 1)];
        rep(i, 1, m) tot[i] += tot[i - 1];
        rrep(i, n, 1) st1[tot[RK((i - 1 ^ step) + 1)]--] = i;

        memset(tot, 0, sizeof tot);
        rep(i, 1, n)++ tot[rk[i]];
        rep(i, 1, m) tot[i] += tot[i - 1];
        rrep(i, n, 1) st[tot[rk[st1[i]]]--] = st1[i];

        rk1[st[1]] = k = 1;
        rep(i, 2, n) {
            if (rk[st[i]] != rk[st[i - 1]] || RK((st[i] - 1 ^ step) + 1) != RK((st[i - 1] - 1 ^ step) + 1))
                ++k;
            rk1[st[i]] = k;
        }
        swap(rk, rk1);
    }

    int j = 0;
    rep(i, 1, n) if (rk[i] == 2) j = i;
    rep(i, 1, n - 1) t[i] = s[(j - 1 ^ i - 1) + 1];
    t[n] = 0;
    cout << (t + 1);
    return 0;
}