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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll p, q;
char c;
string s;

ll good(ll p) {
    if (p <= 0 || p >= n - 1) return 0;
    return (s[p] == 'a' && s[p + 1] == 'b' && s[p + 2] == 'c');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> q >> s; s = '#' + s;
    for (i = 1; i <= n; i++) res += good(i);

    while (q--) {
        cin >> p >> c;
        res -= (good(p - 2) + good(p - 1) + good(p));
        s[p] = c;
        res += (good(p - 2) + good(p - 1) + good(p));

        cout << res << nl;
    }

    return 0;
}