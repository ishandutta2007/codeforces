#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 5e2 + 5, K = 10 + 5, inf = 1e9 + 7;

int n, m, k;
int whor[N][N], wver[N][N];
int ans[N][N][K];

int calans(int x, int y, int k){
    if (ans[x][y][k] != -1){
        return ans[x][y][k];
    }
    if (k == 0){
        return (ans[x][y][k] = 0);
    }
    ans[x][y][k] = inf;
    if (x > 1){
        ans[x][y][k] = min(ans[x][y][k], calans(x - 1, y, k - 1) + 2 * wver[x - 1][y]);
    }
    if (x < n){
        ans[x][y][k] = min(ans[x][y][k], calans(x + 1, y, k - 1) + 2 * wver[x][y]);
    }
    if (y > 1){
        ans[x][y][k] = min(ans[x][y][k], calans(x, y - 1, k - 1) + 2 * whor[x][y - 1]);
    }
    if (y < m){
        ans[x][y][k] = min(ans[x][y][k], calans(x, y + 1, k - 1) + 2 * whor[x][y]);
    }
    return ans[x][y][k];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    memset(ans, -1, sizeof(ans));
    cin >> n >> m >> k;
    ForE(i, 1, n){
        For(j, 1, m){
            cin >> whor[i][j];
        }
    }
    For(i, 1, n){
        ForE(j, 1, m){
            cin >> wver[i][j];
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            if (k & 1){
                cout << -1 << ' ';
                continue;
            }
            cout << calans(i, j, k / 2) << ' ';            
        } cout << endl;
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