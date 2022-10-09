#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll fxp(ll b, ll e, ll m) {
    ll r;
    if (e == 0) return 1;
    if (e % 2 == 0) {
        r = fxp(b, e / 2, m); return (r * r) % m;
    } else {
        r = fxp(b, e - 1, m); return (b * r) % m;
    }
}

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    res = fxp(3, n, m);
    res += (m - 1); res %= m;
    cout << res;

    return 0;
}