#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5;

int n;

int cans;
pii ans[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    if (n == 1){
        cout << 1 << endl;
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }

    int k = (2 * n - 1 + 3 - 1) / 3;
    cans = k;

    while ((2 * (n - 1) - 1 + 3 - 1) / 3 == (k - 1)){
        ans[k] = make_pair(n, n);
        n--; k--;
    }

    int x = k + 1, y = n;
    while (x > k or y > k){
        x--; y--;
    }
    ans[x] = make_pair(x, y);
    for (int tx = x - 1, ty = y + 1; tx >= 1; tx--, ty++){
        if (ty > k){
            ty -= k;
        }
        if (ty < 1){
            ty += k;
        }
        ans[tx] = make_pair(tx, ty);
    }
    for (int tx = x + 1, ty = y - 1; tx <= k; tx++, ty--){
        if (ty > k){
            ty -= k;
        }
        if (ty < 1){
            ty += k;
        }
        ans[tx] = make_pair(tx, ty);
    }
    cout << cans << endl;
    ForE(i, 1, cans){
        cout << ans[i].fi << ' ' << ans[i].se << endl;
    }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/