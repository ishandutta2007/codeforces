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

const ll N = 1000005;

ll n, S;
ll a[N];
ll ans = -1;
vector < ll > V;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf ("%lld", &a[i]);
        S += a[i];
    }
    if (S == 1){
        cout << -1 << endl;
        return 0;
    }
    for (ll i = 2; i * i <= S; i++){
        if (S % i == 0){
            V.pb (i);
            while (S % i == 0)
                S /= i;
        }
    }
    if (S > 1)
        V.pb (S);
    for (ll k : V){
        ll pas = 0;
        ll x, y, A, B;
        ll t = 0, d = 0;
        for (int i = 1; i <= n; i++){
            d++;
            x = a[i] % k;
            y = t;
            t = (x + y) % k;
            if (x + y >= k){
                pas += min (y, k - y) * d;
                d = 0;
                continue;
            }
            if (y * 2 > k){
                pas += x * d;
                continue;
            }
            pas += y * d;
            d = 0;
        }
        if (ans == -1 || ans > pas)
            ans = pas;
    }
    cout << ans << endl;
    return 0;
}