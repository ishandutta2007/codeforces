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

const ll N = 1e6 + 5;

ll n;
pair < ll, ll > P[N];
ll ans;
ll x, y, z;

bool F[N];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (ll i = 1; i <= n; i++){
        cin >> P[i].F;
    }
    for (ll i = 1; i <= n; i++){
        cin >> P[i].S;
    }
    sort (P + 1, P + n + 1);
    P[0].F = -10;
    P[n + 1].F = -10;
    for (int i = 1; i <= n; i++){
        if (P[i].F == P[i - 1].F || P[i].F == P[i + 1].F){
            F[i] = 1;
            ans += P[i].S;
        }
    }
    for (int i = n; i >= 1; i--){
        if (F[i])
            continue;
        for (int j = 1; j <= n; j++){
            if (F[j] == 0)
                continue;
            if ((P[i].F | P[j].F) == P[j].F){
                F[i] = 1;
                break;
            }
        }
        if (F[i])
            ans += P[i].S;
    }
    cout << ans << endl;
    return 0;
}