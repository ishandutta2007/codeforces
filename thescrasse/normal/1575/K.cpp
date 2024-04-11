#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define y1 greniogin

#define INF (ll)1e18
#define mod 1000000007
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll r, c, x1, y1, x2, y2;

ll fxp(ll b, ll e) {
    ll r = 1, k = b;
    while (e != 0) {
        if (e % 2) r = (r * k) % mod;
        k = (k * k) % mod; e /= 2;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> k >> r >> c >> x1 >> y1 >> x2 >> y2;
    a = n * m;
    if (x1 != x2 || y1 != y2) a -= (r * c);

    cout << fxp(k, a) << nl;

    return 0;
}