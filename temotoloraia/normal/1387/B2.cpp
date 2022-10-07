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

int n;
vector < int > g[N];
int S[N], D[N];

void dfs (int k, int p){
    S[k] = 1;
    D[k] = D[p] + 1;
    for (int to : g[k]){
        if (to == p)
            continue;
        dfs (to, k);
        S[k] += S[to];
    }
}

int fin (int k, int p){
    int pas = 0;
    for (int to : g[k]){
        if (to == p)
            continue;
        int t = fin (to, k);
        if (t)
            pas = t;
    }
    if (pas == 0 && S[k] > n/2)
        pas = k;
    return pas;
}

vector < int > V[N];
priority_queue < pair < int, int > > Q;
int nn;
int ans[N], ANS;

void go (int k, int p){
    V[nn].pb (k);
    for (int to : g[k]){
        if (to == p)
            continue;
        go (to, k);
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        ans[i] = i;
    for (int u, v, i = 1; i < n; i++){
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    dfs (1, 0);
    int st = fin (1, 0);
    D[0] = -1;
    dfs (st, 0);
    for (int i = 1; i <= n; i++)
        ANS += D[i];
    cout << ANS*2 << endl;
    nn++;
    V[1].pb (st);
    Q.push ({1, 1});
    for (int to : g[st]){
        nn++;
        go (to, st);
        Q.push ({(int)V[nn].size(), nn});
    }
    while (Q.size() >= 2){
        pair < int, int > A = Q.top();
        Q.pop();
        pair < int, int > B = Q.top();
        Q.pop();
        int x = V[A.S].back();
        int y = V[B.S].back();
        ans[x] = y;
        ans[y] = x;
        V[A.S].pop_back();
        V[B.S].pop_back();
        A.F--;
        B.F--;
        if (A.F)
            Q.push (A);
        if (B.F)
            Q.push (B);
    }
    for (int i = 1; i <= n; i++)
    if (ans[i] == i){
        int x = g[i][0];
        swap (ans[i], ans[x]);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}