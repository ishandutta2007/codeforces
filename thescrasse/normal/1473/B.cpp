#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, n, m, res, flag[10], a, b, q;
string s, t, u, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> q;
    while (q--) {
        cin >> s >> t; a = s.size(); b = t.size(); u = ""; v = "";
        k = a * b; k /= __gcd(a, b);
        for (i = 1; i <= k / a; i++) u += s;
        for (i = 1; i <= k / b; i++) v += t;
        if (u == v) cout << u << nl;
        else cout << -1 << nl;
    }

    return 0;
}