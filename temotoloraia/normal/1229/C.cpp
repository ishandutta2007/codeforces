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


#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
/*
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 1e5 + 5;

vector < int > A[N];
//set < int > B[N];

ll a[N], b[N];

int n, m;

ll ans;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n >> m;
    while (m--){
        int u, v;
        scanf ("%d %d", &u, &v);
        if (u > v)
            swap (u, v);
        A[u].pb (v);
        a[u]++;
        //B[v].insert (u);
        b[v]++;
    }
    for (int i = 1; i <= n; i++){
        ans += a[i] * b[i];
    }
    cout << ans << endl;
    int Q;
    cin >> Q;
    while (Q--){
        int t;
        scanf ("%d", &t);
        ans -= a[t] * b[t];
        b[t] += a[t];
        a[t] = 0;
        for (int k : A[t]){
            ans -= a[k] * b[k];
            A[k].pb (t);
            //B[k].erase (t);
            a[k]++;
            b[k]--;
            ans += a[k] * b[k];
            //B[t].insert (k);
        }
        A[t].clear();
        printf ("%lld\n", ans);
    }
    return 0;
}