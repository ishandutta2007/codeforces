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

const int N = 200005;

int n, k;

int x[N], y[N];

int par[N];

map < pair < int, int >, bool > M;

set < int > S[N];

vector < int > V[N];

int ans;

int parent (int x){
    if (par[x] == x)
        return x;
    return par[x] = parent (par[x]);
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++){
        par[i] = i;
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap (a, b);
        x[i] = a;
        y[i] = b;
        M[{a, b}] = 1;
        V[a].pb (i);
        V[b].pb (i);
    }
    for (int i = 1; i <= n; i++){
        int num = (int)V[i].size();
        for (int j = 0; j + 1 < num; j++){
            int a = V[i][j], b = V[i][j + 1];
            a = parent (a);
            b = parent (b);
            if (a != b)
                par[a] = b;
        }
    }
    for (int i = 1; i <= k; i++){
        int a = parent (i);
        S[a].insert (x[i]);
        S[a].insert (y[i]);
    }
    for (int i = 1; i <= k; i++){
        int num = (int)S[i].size();
        if (num > 1)
            ans += num - 1;
    }
    cout << k - ans << endl;
    return 0;
}