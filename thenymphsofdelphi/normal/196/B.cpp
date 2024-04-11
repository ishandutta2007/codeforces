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

const int N = 1e3 + 5e2 + 5;

int n, m;
char a[N][N];

bool vis[N][N]; pii pos[N][N];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool ans;

bool ff(int x, int y){
    For(d, 0, 4){
        int tx = (x + dx[d] + n) % n, ty = (y + dy[d] + m) % m, txx = pos[x][y].fi + dx[d], tyy = pos[x][y].se + dy[d];
        if (a[tx][ty] != '.'){
            continue;
        }
        if (vis[tx][ty] and pos[tx][ty] == make_pair(txx, tyy)){
            continue;
        }
        if (vis[tx][ty]){
            return 1;
        }
        vis[tx][ty] = 1; pos[tx][ty] = make_pair(txx, tyy);
        if (ff(tx, ty)){
            return 1;
        }
    }
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    For(i, 0, n){
        For(j, 0, m){
            cin >> a[i][j];
        }
    }

    For(i, 0, n){
        For(j, 0, m){
            if (a[i][j] == 'S'){
                a[i][j] = '.';
                vis[i][j] = 1; pos[i][j] = make_pair(i, j);
                ans = ff(i, j);
                break;
            }
        }
    }
    if (ans){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
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