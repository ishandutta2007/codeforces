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

const int N = 4e5 + 5, LN = 19;

int n;
int a[N];

pair <int, pair <ll, int>> b[N], c[LN][N];

pair <ll, int> add(const pair <ll, int> &lhs, const pair <ll, int> &rhs){
    return make_pair(lhs.fi + rhs.fi, lhs.se + rhs.se);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 2, n){
        cin >> a[i];
    }

    b[0] = make_pair(0, make_pair(0, 0));
    b[1] = make_pair(1, make_pair(0, 0));
    ForE(i, 2, n){
        if (i + a[i] > n){
            b[i] = make_pair(0, make_pair(a[i], 0));
        }
        else{
            b[i] = make_pair(n + i + a[i], make_pair(a[i], 0));
        }
    }
    b[n + 1] = make_pair(0, make_pair(0, 1));
    ForE(i, 2, n){
        if (i - a[i] < 1){
            b[n + i] = make_pair(0, make_pair(a[i], 0));
        }
        else{
            b[n + i] = make_pair(i - a[i], make_pair(a[i], 0));
        }
    }

    ForE(i, 0, 2 * n){
        c[0][i] = b[i];
    }
    For(j, 1, LN){
        ForE(i, 0, 2 * n){
            c[j][i] = make_pair(c[j - 1][c[j - 1][i].fi].fi, add(c[j - 1][i].se, c[j - 1][c[j - 1][i].fi].se));
        }
    }

    For(val, 1, n){
        if (c[LN - 1][n + val + 1].fi != 0){
            cout << -1 << endl;
        }
        else{
            pair <ll, int> ans = add(make_pair(0, 1), c[LN - 1][n + val + 1].se);
            cout << ans.fi + (ll)ans.se * val << endl;
        }
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