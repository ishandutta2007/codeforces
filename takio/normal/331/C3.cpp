#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 800, mod = 1e9 + 7;

LL n;

map <pii, pii> mp;

pii solve (LL n, int m) {
//    cout << n << ' ' << m << endl;
    if (n < 10) return pii (1, n > m ? 0 : n - m);
    if (mp.find (pii (n, m)) != mp.end()) return mp[pii (n, m)];
    LL p = 1;
    while (p <= n / 10) p *= 10;
    pii t = solve (n - n / p * p, max (m, (int) (n / p)));
    LL tn = n / p * p + t.yy;
    pii res = solve (tn, m);
    res.xx += t.xx;
    return mp[pii (n, m)] = res;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n;
    if (n == 0) cout << 0;
    else cout << solve (n, 0).xx;
}