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

const int N = 1e3 + 5, Q = 1e6 + 5;

struct query_t{
    int x1, y1, x2, y2;

    query_t(){

    }
};

int n, m, q;
bitset <N> a[N];
query_t b[Q];

bool ans[Q];

bitset <N> c[N][N], d[N], e[N];

void dnc(int xl, int xr, vi vidxb){
    int xm = (xl + xr) >> 1;
    ForE(y, 1, m){
        c[xm][y] = 0;
        if (a[xm][y]){
            c[xm][y][y] = 1;
        }
    }
    FordE(y, m, 1){
        if (a[xm][y]){
            c[xm][y] |= c[xm][y + 1];
        }
    }
    FordE(x, xm - 1, xl){
        FordE(y, m, 1){
            if (a[x][y]){
                c[x][y] = c[x][y + 1] | c[x + 1][y];
            }
            else{
                c[x][y] = 0;
            }
        }
    }
    ForE(y, 1, m){
        d[y] = c[xm][y];
    }
    ForE(y, 1, m){
        c[xm][y] = 0;
        if (a[xm][y]){
            c[xm][y][y] = 1;
        }
    }
    ForE(y, 1, m){
        if (a[xm][y]){
            c[xm][y] |= c[xm][y - 1];
        }
    }
    ForE(x, xm + 1, xr){
        ForE(y, 1, m){
            if (a[x][y]){
                c[x][y] = c[x - 1][y] | c[x][y - 1];
            }
            else{
                c[x][y] = 0;
            }
        }
    }
    ForE(y, 1, m){
        e[y] = c[xm][y];
    }
    vi vidxbl, vidxbr;
    Fora(idx, vidxb){
        if (b[idx].x2 < xm){
            vidxbl.emplace_back(idx);
        }
        else if (b[idx].x1 > xm){
            vidxbr.emplace_back(idx);
        }
        else{
            ans[idx] = ((b[idx].x1 == xm ? d[b[idx].y1] : c[b[idx].x1][b[idx].y1]) & (b[idx].x2 == xm ? e[b[idx].y2] : c[b[idx].x2][b[idx].y2])).any();
        }
    }
    if (isz(vidxbl)){
        dnc(xl, xm - 1, vidxbl);
    }
    if (isz(vidxbr)){
        dnc(xm + 1, xr, vidxbr);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    // cin >> q;
    ForE(i, 1, n){
        ForE(j, 1, m){
            char c; cin >> c;
            a[i][j] = (c == '.');
        }
    }
    cin >> q;
    ForE(i, 1, q){
        cin >> b[i].x1 >> b[i].y1 >> b[i].x2 >> b[i].y2;
    }

    vi vidxb;
    ForE(i, 1, q){
        if (b[i].x1 <= b[i].x2 and b[i].y1 <= b[i].y2){
            vidxb.emplace_back(i);
        }
    }
    dnc(1, n, vidxb);
    ForE(i, 1, q){
        if (ans[i]){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
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