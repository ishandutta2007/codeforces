// 1364E
// X-OR

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 3010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, p[maxn], x, y, z, r1, r2;

ll ask(ll a, ll b) {
    ll x;
    cout << "? " << a _ b << nf;
    cin >> x; return x;
}

void clm() {
    cout << "! ";
    for (i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << nf; exit(0);
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n;

    for (i = 1; i <= n; i++) p[i] = i;
    shuffle(p + 1, p + n + 1, rng);

    x = p[1]; y = p[2]; r1 = -1;
    for (i = 3; i <= n; i++) {
        if (r1 == -1) r1 = ask(x, y);
        z = p[i]; r2 = ask(x, z);
        if (r1 > r2) {
            y = z; r1 = r2;
        } else if (r1 == r2) {
            x = z; r1 = -1;
        }
    }

    while (true) {
        z = uniform_int_distribution<ll>(1, n)(rng);
        if (z == x || z == y) continue;
        r1 = ask(x, z); r2 = ask(y, z);
        if (r1 == r2) continue;
        if (r1 > r2) m = y;
        else m = x;
        break;
    }

    for (i = 1; i <= n; i++) {
        if (i == m) a[i] = 0;
        else a[i] = ask(i, m);
    }

    clm();

    return 0;
}