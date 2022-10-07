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
/*
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int N = 200005;

int n, m;
int a[N];
pair < int, int > P[N];
int k[N], pos[N];
int ans[N];

vector < int > V[N];

ordered_set S;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf ("%d", &P[i].F);
        a[i] = P[i].F;
        P[i].F = -P[i].F;
        P[i].S = i;
    }
    sort (P + 1, P + n + 1);
    cin >> m;
    for (int i = 1; i <= m; i++){
        scanf ("%d %d", &k[i], &pos[i]);
        V[k[i]].pb (i);
    }
    for (int i = 1; i <= n; i++){
        S.insert (P[i].S);
        for (int x : V[i]){
            ans[x] = *(S.find_by_order(pos[x] - 1));
            ans[x] = a[ans[x]];
        }
    }
    for (int i = 1; i <= m; i++)
        printf ("%d\n", ans[i]);
    return 0;
}