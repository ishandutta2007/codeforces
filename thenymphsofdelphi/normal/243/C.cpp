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

const int N = 2e3 + 5, inf = 1e9 + 7;

int n;
pii a[N];

map <int, int> mppx, mppy;
int mx, my;
int lenx[N], leny[N];

int b[N][N];
queue <pii> qu;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    a[0] = make_pair(0, 0);
    ForE(i, 1, n){
        char c; int len; cin >> c >> len;
        int dx = 69, dy = 69;
        switch (c){
            case 'U': dx = 0; dy = 1; break;
            case 'D': dx = 0; dy = -1; break;
            case 'R': dx = 1; dy = 0; break;
            case 'L': dx = -1; dy = 0; break;
        }
        a[i] = make_pair(a[i - 1].fi + dx * len, a[i - 1].se + dy * len);
    }

    mppx[-inf]++; mppx[inf]++;
    mppy[-inf]++; mppy[inf]++;
    ForE(i, 0, n){
        mppx[a[i].fi]++; mppx[a[i].fi + 1]++;
        mppy[a[i].se]++; mppy[a[i].se + 1]++;
    }
    {
        Fora(&elem, mppx){
            elem.se = ++mx;
        }
        Fora(&elem, mppy){
            elem.se = ++my;
        }
        ForE(i, 0, n){
            a[i].fi = mppx[a[i].fi];
            a[i].se = mppy[a[i].se];
        }
        for (auto itr = mppx.begin(); itr != prev(mppx.end()); itr++){
            lenx[itr->se] = next(itr)->fi - itr->fi;
        }
        for (auto itr = mppy.begin(); itr != prev(mppy.end()); itr++){
            leny[itr->se] = next(itr)->fi - itr->fi;
        }
        memset(b, -1, sizeof(b));
        ForE(i, 0, n){
            b[a[i].fi][a[i].se] = 1;
        }
        ForE(i, 1, n){
            ForE(x, min(a[i - 1].fi, a[i].fi), max(a[i - 1].fi, a[i].fi)){
                ForE(y, min(a[i - 1].se, a[i].se), max(a[i - 1].se, a[i].se)){
                    b[x][y] = 1;
                }
            }
        }
    }

    b[1][1] = 0;
    qu.emplace(1, 1);
    while (!qu.empty()){
        int x, y; tie(x, y) = qu.front(); qu.pop();
        For(d, 0, 4){
            int tx = x + dx[d], ty = y + dy[d];
            if (1 <= tx and tx <= mx and 1 <= ty and ty <= my and b[tx][ty] == -1){
                b[tx][ty] = 0;
                qu.emplace(tx, ty);
            }
        }
    }
    ll ans = 0;
    ForE(i, 1, mx){
        ForE(j, 1, my){
            if (b[i][j] != 0){
                ans += (ll)lenx[i] * leny[j];
            }
        }
    }
    cout << ans << endl;
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