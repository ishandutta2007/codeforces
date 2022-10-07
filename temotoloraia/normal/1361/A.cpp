#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
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

const int N = 500005, MOD = 998244353;

int n, m;
int a[N];
pair < int, int > P[N];
vector < int > g[N];

void solve () {
    cin >> n >> m;
    while (m--){
        int u, v;
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        P[i] = {a[i], i};
    }
    for (int i = 1; i <= n; i++){
        vector < int > v;
        for (int x : g[i])
            v.pb (a[x]);
        sort (v.begin(), v.end());
        int last = 0;
        for (int x : v){
            if (x > last+1)
                break;
            if (x == last + 1)
                last++;
        }
        if (last != a[i] - 1){
            cout << -1 << endl;
            return;
        }
    }
    sort (P + 1, P + n + 1);
    for (int i = 1; i <= n; i++)
        cout << P[i].S << " ";
    cout << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T=1;
    //cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}