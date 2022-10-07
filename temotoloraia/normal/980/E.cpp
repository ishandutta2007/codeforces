#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n, K;
int P[1000005][22];
bool F[1000005];
int D[1000005];
vector < int > g[1000005];
void dfs (int k, int p){
    P[k][0] = p;
    D[k] = D[p] + 1;
    for (int i = 1; i <= 20; ++i)
        P[k][i] = P[P[k][i - 1]][i - 1];
    for (int i = 0; i < g[k].size(); ++i)
        if (g[k][i] != p)
            dfs (g[k][i], k);
}
int main()
{
    cin>>n>>K;
    int u, v;
    for (int i = 1; i < n; ++i){
        scanf ("%d %d", &u, &v);
        g[u].pb (v);
        g[v].pb (u);
    }
    dfs (n, 0);
    K = n - K - 1;
    int p = 1;
    F[n] = 1;
    int I, x;
    for (int i = n - 1; i >= 1; --i){
        if (F[i])
            continue;
        I = i;
        for (int j = 20; j >= 0; --j){
            if (P[I][j] == 0)
                continue;
            if (F[P[I][j]] == 0)
                I = P[I][j];
        }
        I = P[I][0];
        if (D[i] - D[I] > K)
            continue;
        K -= D[i] - D[I];
        x = i;
        while (x != I){
            F[x] = 1;
            x = P[x][0];
        }
    }
    for (int i = 1; i <= n; ++i)
        if (F[i] == 0)
            printf ("%d ", i);
    return 0;
}