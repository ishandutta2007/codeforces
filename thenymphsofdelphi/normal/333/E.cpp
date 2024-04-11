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

const int N = 3e3 + 5;

int n;
pii a[N];

int squared_distance(const pii &lhs, const pii &rhs){
    return (lhs.fi - rhs.fi) * (lhs.fi - rhs.fi) + (lhs.se - rhs.se) * (lhs.se - rhs.se);
}

vector <tuple <int, int, int>> b;

bitset <N> bs[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i].fi >> a[i].se;
    }

    ForE(i, 1, n){
        ForE(j, i + 1, n){
            int dist = squared_distance(a[i], a[j]);
            b.emplace_back(dist, i, j);
        }
    }
    sort(bend(b), [&](const tuple <int, int, int> &lhs, const tuple <int, int, int> &rhs){
        return get<0>(lhs) > get<0>(rhs);
    });
    Fora(&edge, b){
        int i = get<1>(edge), j = get<2>(edge);
        bs[i].set(j); bs[j].set(i);
        if ((bs[i] & bs[j]).any()){
            int dist = get<0>(edge);
            cout << fixed << setprecision(12) << sqrtl(dist) / 2 << endl;
            return 0;
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