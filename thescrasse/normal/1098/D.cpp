#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 35

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll bt[maxn], p2[maxn], tt, cr, q, x;
char c;
multiset<ll> bk[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    p2[0] = 1;
    for (i = 1; i < maxn; i++) p2[i] = 2 * p2[i - 1];

    cin >> q;
    while (q--) {
        cin >> c >> x;
        for (i = 1;; i++) {
            if (p2[i] > x) {
                b = i - 1; break;
            }
        }
        if (c == '+') {
            bk[b].insert(x); bt[b] += x; cr++;
        } else {
            bk[b].erase(bk[b].find(x)); bt[b] -= x; cr--;
        }

        tt = 0; res = 0;
        for (i = 0; i < maxn; i++) {
            if (bk[i].empty()) continue;
            m = (*bk[i].begin());
            res += (m > 2 * tt); tt += bt[i];
            // cout << i _ m _ res << nl;
        }

        res = cr - res;
        cout << res << nl;
    }

    return 0;
}