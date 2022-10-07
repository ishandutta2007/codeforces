#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
//#define int long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

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


const int N = 200005, INF = 1e9;

int n, m, k, K;
vector < pair < int, int > > G[N];
int F[N][50];

int nn;
int id[10][10];
int mas[50], ans;
pair < int, int > xy[50];
bool g[50][50];

void go (int t){
    if (t > k){
        ans++;
        return;
    }
    for (int ind, i = 1; i <= t; i++){
        ind = id[t][i];
        if (mas[ind])
            continue;
        for (int to = 1; to <= K; to++)
            if (g[ind][to])
                mas[to]++;
        go (t+1);
        for (int to = 1; to <= K; to++)
            if (g[ind][to])
                mas[to]--;
    }
}

void solve () {
    cin >> n >> m >> k;
    K = k * (k+1)/2;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= i; j++){
            nn++;
            xy[nn] = {i, j};
            id[i][j] = nn;
        }
    while (m--){
        int u, v, w;
        //cin >> u >> v >> w;
        scanf ("%d %d %d", &u, &v, &w);
        G[u].pb ({w, v});
    }
    for (int i = 1; i <= n; i++){
        sort (G[i].begin(), G[i].end());
        nn = (int)G[i].size();
        for (int j = 0; j < nn; j++){
            F[G[i][j].S][id[nn][j+1]]++;
        }
    }
    for (int i = 1; i <= n; i++){
        vector < int > V;
        for (int j = 1; j <= K; j++){
            if (F[i][j] == 0)
                continue;
            V.pb (j);
            if (F[i][j] > 1)
                mas[j] = 1;
        }
        for (int j = 0; j < V.size(); j++)
            for (int l = 0; l < V.size(); l++)
                if (j != l)
                    g[V[j]][V[l]] = 1;
    }
    go (1);
    cout << ans << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    int T = 1;
    //cin >> T;
    while (T--)
        solve ();
}