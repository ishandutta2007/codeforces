// 547C
// Mike and Foam

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010
#define maxp 500010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, f[500010], er[500010], q, x, y, s, o;
bool tk[500010];
vector<ll> fc;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> q;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (i = 0; i < maxp; i++) er[i] = i;
    for (i = 2; i < maxp; i++) {
        if (er[i] == i) {
            for (j = 2 * i; j < maxp; j += i) er[j] = i;
        }
    }

    res = 0;
    while (q--) {
        fc.clear();
        cin >> x; o = x; x = a[x - 1];
        k = x;
        while (k != 1) {
            m = er[k]; k /= m;
            if (fc.empty() || fc.back() != m) fc.pb(m);
        }

        s = fc.size();
        for (i = 0; i < (1 << s); i++) {
            y = 1;
            for (j = 0; j < s; j++) {
                if ((i >> j) & 1 == 1) {
                    y *= fc[j];
                }
            }
            b = __builtin_popcountll(i); b %= 2; b = 1 - 2 * b;
            if (tk[o] == false) {
                res += b * f[y]; f[y]++;
            } else {
                f[y]--; res -= b * f[y];
            }
        }

        tk[o] = (tk[o] + 1) % 2;

        cout << res << nl;
    }

    return 0;
}