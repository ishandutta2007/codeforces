#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

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

const int N = 1005, MOD = 1e9 + 7;

int n;
int S[N];
int u[N], v[N];

vector < int > g[N];

pair < int, int > P[N];

int D[N];

void dfs (int k, int p){
    S[k] = 1;
    for (int to : g[k]){
        if (to == p)
            continue;
        dfs (to, k);
        S[k] += S[to];
    }
}

vector < int > V1, V2;
int nn;
int mas[N];

map < pair < int, int >, int > M;

void go (int k, int p){
    D[k] = mas[nn];
    nn--;
    int dif = D[k] - D[p];
    M[{k, p}] = dif;
    M[{p, k}] = dif;
    for (int to : g[k]){
        if (to != p)
            go (to, k);
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        cin >> u[i] >> v[i];
        g[u[i]].pb (v[i]);
        g[v[i]].pb (u[i]);
    }
    ll ans = 2 * n * n / 9;
    for (int I = 1; I <= n; I++){
        dfs (I, 0);
        int m = (int)g[I].size();
        for (int i = 0; i < m; i++){
            P[i + 1] = {S[g[I][i]], g[I][i]};
        }
        sort (P + 1, P + m + 1);
        V1.clear();
        V2.clear();
        ll x = 0, y = 0;
        for (int i = m; i >= 1; i--){
            if (x <= y){
                V1.pb (P[i].S);
                x += P[i].F;
            }
            else {
                V2.pb (P[i].S);
                y += P[i].F;
            }
        }
        if (x * y + x + y < ans)
            continue;
        nn = x;
        for (int i = 1; i <= nn; i++)
            mas[i] = nn - i + 1;
        for (int no : V1){
            go (no, I);
        }
        nn = y;
        for (int i = nn; i >= 1; i--)
            mas[nn - i + 1] = i * (x + 1);
        for (int no : V2){
            go (no, I);
        }
        for (int i = 1; i < n; i++)
            cout << u[i] << " " << v[i] << " " << M[{u[i], v[i]}] << endl;
        return 0;
    }
    return 0;
}