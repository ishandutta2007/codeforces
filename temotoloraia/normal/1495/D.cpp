#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
/*
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 405, MOD = 998244353;

int n, m;
vector < int > g[N];
int ans[N][N];
int D[N][N];
int mas[N];

void solve () {
    cin >> n >> m;
    while (m--){
        int u, v;
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans[i][j] = 1;
    queue < int > Q;
    for (int I = 1; I <= n; I++){
        Q.push (I);
        for (int i = 1; i <= n; i++)
            D[I][i] = n+1;
        D[I][I] = 0;
        while (Q.size() > 0){
            int k = Q.front();
            Q.pop();
            for (int to : g[k]){
                if (D[I][to] > D[I][k]+1){
                    D[I][to] = D[I][k]+1;
                    Q.push (to);
                }
            }
        }
    }
    for (int X = 1; X <= n; X++)
        for (int Y = X; Y <= n; Y++){
            for (int i = 0; i < n; i++)
                mas[i] = 0;
            int id = 0, ind, cnt = 0;
            for (int i = 1; i <= n; i++){
                if (D[i][X] + D[i][Y] == D[X][Y]){
                    if (mas[D[i][X]] > 0){
                        ans[X][Y] = 0;
                        break;
                    }
                    mas[D[i][X]] = i;
                    continue;
                }
                cnt = 0;
                id = (D[X][i] + D[X][Y] - D[i][Y])/2;
                for (int to : g[i]){
                    if (D[X][to] == D[X][i]-1 && D[Y][to] == D[Y][i]-1)
                        cnt++;
                }
                ans[X][Y] = ans[X][Y] * cnt % MOD;
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            ans[j][i] = ans[i][j];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}

main()
{
  //  freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
  //  cin >> T;
    while (T--){
        solve ();
    }
}