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

const int N = 100005;

int n, m;
int u[N], v[N];
map < pair < int, int >, bool > M;
int A;
vector < int > g[N];
vector < int > V, vv;
bool fix[N];

queue < int > Q;

int par[N];

int parent (int x){
    if (par[x] == x)
        return x;
    return par[x] = parent (par[x]);
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> u[i] >> v[i];
        M[{u[i],v[i]}] = 1;
        M[{v[i],u[i]}] = 1;
        g[u[i]].pb (v[i]);
        g[v[i]].pb (u[i]);
    }
    A = 1;
    for (int i = 2; i <= n; i++)
        if ((int)g[i].size() < (int)g[A].size())
            A = i;
    for (int x : g[A]){
        fix[x] = 1;
        V.pb (x);
    }
    for (int i = 1; i <= n; i++)
        if (fix[i] == 0)
            Q.push (i);
    while (Q.size() > 0){
        int k = Q.front();
        Q.pop();
        vv.clear();
        for (int x : V){
            if (M[{k, x}] == 1)
                vv.pb (x);
            else {
                fix[x] = 0;
                Q.push (x);
            }
        }
        V = vv;
    }
    int nn = (int)V.size();
    int num = nn;
    for (int i = 0; i < nn; i++)
        par[V[i]] = V[i];
    for (int i = 0; i < nn; i++)
    for (int j = i + 1; j < nn; j++){
        int x = V[i], y = V[j];
        if (M[{x, y}] == 1)
            continue;
        x = parent (x);
        y = parent (y);
        if (x == y)
            continue;
        par[x] = y;
        num--;
    }
    cout << num << endl;
    return 0;
}