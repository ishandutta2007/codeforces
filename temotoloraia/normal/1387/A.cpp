#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll __int128
//#define ll long long
#define int long long
//#define int __int128
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


const int N = 200005;

int n, m;
vector < int > V[N];

int par[N], d[N];
int op[N];
int val[N];
bool F[N];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        V[i].pb (i);
        par[i] = i;
        d[i] = 0;
        op[i] = i+n;
        op[i+n] = i;
    }
    while (m--){
        int u, v, w;
        cin >> u >> v >> w;
        w -= d[u] + d[v];
        u = par[u];
        v = par[v];
        if (v == op[u]){
            if (w == 0)
                continue;
            cout << "NO" << endl;
            return 0;
        }
        if (u == v){
            if (F[u]){
                if (val[u] != w){
                    cout << "NO" << endl;
                    return 0;
                }
            }
            else {
                F[u] = 1;
                val[u] = w;
                F[op[u]] = 1;
                val[op[u]] = -w;
            }
            continue;
        }
        int x = (int)V[u].size() + (int)V[op[u]].size();
        int y = (int)V[v].size() + (int)V[op[v]].size();
        if (x > y){
            swap (u, v);
            swap (x, y);
        }
        if (F[u] && F[v]){
            if (val[u] + val[v] != w*2){
                cout << "NO" << endl;
                return 0;
            }
        }
        else if (F[u]){
            F[v] = 1;
            val[v] = w*2 - val[u];
            F[op[v]] = 1;
            val[op[v]] = val[u] - w*2;
        }
        for (int X : V[u]){
            d[X] += w;
            par[X] = op[v];
            V[op[v]].pb (X);
        }
        V[u].clear();
        for (int X : V[op[u]]){
            d[X] -= w;
            par[X] = v;
            V[v].pb (X);
        }
        V[op[u]].clear();
    }
    for (int u = 1; u <= n; u++){
        if (F[u]==1 || par[u] != u)
            continue;
        vector < int > A;
        for (int x : V[u]){
            A.pb (-d[x]);
        }
        for (int x : V[op[u]]){
            A.pb (d[x]);
        }
        sort (A.begin(), A.end());
        int nn = (int)A.size();
        val[u] = A[nn/2]*2;
        val[u+n] = -val[u];
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++){
        if (par[i] != i)
            val[i] = val[par[i]] + d[i]*2;
        int t = abs (val[i])/2;
        if (val[i] < 0)
            cout << "-";
        cout << t;
        if (val[i]&1)
            cout << ".5";
        cout << " ";
    }
}