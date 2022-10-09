// 1406E
// Deleting Numbers

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010
#define sq 100

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, er[maxn], s, cr, x, y;
vector<ll> pr, sl;

ll ask(char x, ll a) {
    cout << x << ' ' << a << nf;
    if (x == 'C') exit(0);
    cin >> a; return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n;
    for (i = 0; i <= n; i++) er[i] = i;
    for (i = 2; i <= n; i++) {
        if (er[i] == i) {
            pr.pb(i);
            for (j = 2 * i; j <= n; j += i) er[j] = i;
        }
    }

    cr = n; s = pr.size();
    for (i = 0; i < s; i += sq) {
        k = 0;
        for (j = i; j < min(s, i + sq); j++) {
            if (pr[j] > n) continue;
            cr -= ask('B', pr[j]);
        }
        y = ask('A', 1);
        if (cr != y) {
            cr = y;
            for (j = i; j < min(s, i + sq); j++) {
                x = pr[j];
                while (ask('B', x) == 1) {
                    sl.pb(pr[j]); x *= pr[j];
                    if (x > n) break;
                }
            }
        }
    }

    res = 1;
    for (auto u : sl) res *= u;
    ask('C', res);

    return 0;
}