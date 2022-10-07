#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define ll long long
#define F first
#define S second
using namespace std;

const int N = 505, MOD = 1e18 + 7;

int n, m;
int D[N][N];
//map < int, int > M;
//vector < pair < int, int > > g[N];
int DP[N][N];
priority_queue < pair < int, int > > Q[N*N/2];
bool fix[N];

void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            D[i][j] = DP[i][j] = MOD;
    vector < int > V;
    for (int u, v, w, i = 1; i <= m; i++){
        cin >> u >> v >> w;
        //cout << u << v << " " << w << endl;
        D[u][v] = min (D[u][v], w);
        D[v][u] = D[u][v];
        //cout << D[1][7] << endl;
    }
    //cout << D[1][7] << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            if (D[i][j] == MOD)
                continue;
            DP[i][j] = DP[j][i] = 1;
        }
    //cout << D[1][7] << endl;
    for (int l = 1; l <= n; l++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++){
                DP[i][j] = min (DP[i][j], DP[i][l] + DP[l][j]);
                //DP[j][i] = DP[i][j];
            }
    for (int i = 1; i <= n; i++)
        DP[i][i] = 0;
    int ANS = MOD;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        if (D[i][j] < MOD)
            ANS = min (ANS, D[i][j] * (DP[1][i]+1+DP[j][n]));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (D[i][j] < MOD)
            for (int l = 1; l <= n; l++){
                int dd = min (DP[l][i], DP[l][j]);
            ANS = min (ANS, D[i][j] * (DP[1][l]+2+dd+DP[l][n]));
            }
    cout << ANS << endl;
    /*
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (D[i][j] < MOD){
                for (int l = 1; l <= n; l++)
                    if (DP[j][l] < MOD/D[i][j])
                        D[i][l] = min (D[i][l], D[i][j]*(DP[j][l]+1));
            }
    cout << D[1][7] << endl;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++){
            if (D[i][j] < MOD && M[D[i][j]] == 0){
                V.pb (D[i][j]);
                M[D[i][j]] = 1;
            }
        }
    M.clear();
    m = (int)V.size();
    sort (V.begin(), V.end());
    reverse (V.begin(), V.end());
    for (int i = 0; i < m; i++){
        M[V[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            if (D[i][j] == MOD)
                continue;
            D[i][j] = M[D[i][j]];
            //g[i].pb ({D[i][j], j});
        }
    //priority_queue < pair < pair < int, int >, int > > Q;
    //Q.push ({{MOD, 0},   1});
    Q[0].push ({0, 1});
    int ANS = MOD;
    for (int I = 0; I < m; I++){
        while (Q[I].size() > 0){
            int k = Q[I].top().S, d = -Q[I].top().F;
            //cout << I << " " << V[I] << " " << k << " " << d << endl;
            Q[I].pop();
            if (fix[k])
                continue;
            if (k == n)
                ANS = min (ANS, d);
            fix[k] = 1;
            for (int p, to = 1; to <= n; to++)
                if (D[k][to] < MOD){
                    //p = max (I, D[k][to]);
                    p = D[k][to];
                    if (p >= I)
                        Q[p].push ({-d-V[p], to});
                }
        }
        for (int i = 1; i <= n; i++)
            fix[i] = 0;
    }
    cout << ANS << endl;*/





    for (int i = 1; i <= n; i++){
        //g[i].clear();
        for (int j = 1; j <= n; j++)
            D[i][j] = DP[i][j] = 0;

    }
    //M.clear();
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve();
    }
    return 0;
}