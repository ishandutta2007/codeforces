#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define double long double
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
#define Ptest(x) return cout << x << endl, 0;

typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e3 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

bool squares[N][N];
int adj[N][N], n, m, q, ans[N][N], inians;
bool vis[N][N];
int x[4] = {0, 1, -1, 0};
int y[4] = {1, 0, 0, -1};
vii a;

void ff(int i, int j){
    if (!i || i > n || !j || j > m || vis[i][j] || !squares[i][j]){
        return;
    }
    vis[i][j] = 1;
    inians += adj[i][j];
    a.pb(mp(i, j));
    for (int k = 0; k < 4; k++){
    	ff(i + x[k], j + y[k]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if (c == '.'){
                squares[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (!squares[i][j]){
                adj[i][j] = 0;
            }
            else{
                for (int k = 0; k < 4; k++){
                    if (!squares[i + x[k]][j + y[k]]){
                        adj[i][j]++;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 0; k < a.size(); k++){
                vis[a[k].fi][a[k].se] = 0;
            }
            a.clear();
            if (!ans[i][j]){
                ff(i, j);
            }
            for (int k = 0; k < a.size(); k++){
                ans[a[k].fi][a[k].se] = inians;
            }
            inians = 0;
        }
    }
    for (int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        cout << ans[x][y] << endl;
    }
}

/*
----------------------------------+
INPUT:                            |
==============================    |
5 6 3
******
*..*.*
******
*....*
******
2 2
2 5
4 3

==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
6
4
10

==============================    |
----------------------------------+
*/