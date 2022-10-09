#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 20500010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, c, d, x;
const int N = 20500000;
int er[N+1];
vector<int> pr;

ll solve(ll g) {
    ll res, l, k, y;
    if ((x + d * g) % c != 0) return 0;
    l = (x + d * g) / c;
    if (l % g != 0) return 0;
    k = l / g; res = 1;
    while (k != 1) {
        y = er[k]; res *= 2;
        while (er[k] == y) k /= y;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (int i=2; i<=N; ++i) {
        if (er[i] == 0) {
            er[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=er[i] && i*pr[j]<=N; ++j)
            er[i * pr[j]] = pr[j];
    }

    cin >> t;
    while (t--) {
        cin >> c >> d >> x; res = 0;
        for (i = 1; i * i <= x; i++) {
            if (x % i != 0) continue;
            res += solve(i);
            if (x / i != i) res += solve(x / i);
        }

        cout << res << nl;
    }

    return 0;
}