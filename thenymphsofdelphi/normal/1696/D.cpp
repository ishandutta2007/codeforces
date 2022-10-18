#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = l; i < r; i++)
#define ForE(i, l, r) for (auto i = l; i <= r; i++)
#define FordE(i, l, r) for (auto i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pair <int, int>>;
using vvi = vector <vector <int>>;

const int N = 2e5 + 5e4 + 5, LN = 18;

int n;
int a[N];

pii sptbmn[LN][N];
pii sptbmx[LN][N];

pii query_min(int l, int r){
    int z = __lg(r - l + 1);
    return min(sptbmn[z][l], sptbmn[z][r - (1 << z) + 1]);
}

pii query_max(int l, int r){
    int z = __lg(r - l + 1);
    return max(sptbmx[z][l], sptbmx[z][r - (1 << z) + 1]);
}

int dist(int l, int r, int prevtype = 0, int side = 0){
    if (l == r){
        return 0;
    }
    if (l == r - 1){
        return 1;
    }

    int type = (prevtype == 0 ? 1 : prevtype * -1);
    pii cac = (type == 1 ? query_max(l, r) : query_min(l, r));
    int m = cac.se;
    if (prevtype == 0){
        return dist(l, m, type, 1) + dist(m, r, type, -1);
    }
    if (side == 1){
        return dist(l, m, type, side) + 1;
    }
    else{
        return 1 + dist(m, r, type, side);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    ForE(i, 1, n){
        sptbmn[0][i] = make_pair(a[i], i);
        sptbmx[0][i] = make_pair(a[i], i);
    }
    For(j, 1, LN){
        ForE(i, 1, n - (1 << j) + 1){
            sptbmn[j][i] = min(sptbmn[j - 1][i], sptbmn[j - 1][i + (1 << (j - 1))]);
            sptbmx[j][i] = max(sptbmx[j - 1][i], sptbmx[j - 1][i + (1 << (j - 1))]);
        }
    }

    cout << dist(1, n) << endl;
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