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

const int N = 1000005;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }
    ll x = 0;
    for (ll i = 2; i * i <= n; i++){
        if (n % i == 0){
            if (x){
                cout << 1 << endl;
                return 0;
            }
            x = i;
            while (n % i == 0)
                n /= i;
            continue;
        }
    }
    if (n > 1)
        for (ll i = n; i <= n; i++)
            if (n % i == 0){
                if (x){
                    cout << 1 << endl;
                    return 0;
                }
                x = i;
                while (n % i == 0)
                    n /= i;
                continue;
            }
    cout << x << endl;
    return 0;
}