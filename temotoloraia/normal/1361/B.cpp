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



const int N = 1000005, MOD = 1e9+7, INF = 1e8;


int POWER (int x, int y){
    int ans = 1;
    while (y){
        if (y&1)
            ans = ans * x % MOD;
        y >>= 1;
        x = x * x % MOD;
    }
    return ans;
}

int n, p;
int a[N], b[N];

void solve () {
    scanf ("%lld %lld", &n, &p);
    int x = 1, len = 0;
    if (p > 1){
        while (x * p <= INF){
            x *= p;
            len++;
        }
    }
    else
        len = INF;
    for (int i = 1; i <= n; i++)
        scanf ("%lld", &a[i]);
    sort (a + 1, a + n + 1);
    reverse (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        b[i] = POWER (p, a[i]);
    int ans = 0;
    int mog = 0;
    int ind = 1;
    while (ind <= n){
        if (mog == INF){
            ans -= b[ind];
            ind++;
            continue;
        }
        if (mog){
            mog--;
            ans -= b[ind];
        }
        else {
            mog++;
            ans += b[ind];
        }
        if (mog) {
            if (a[ind] - a[ind+1] <= len){
                mog = mog * POWER (p, a[ind] - a[ind+1]);
                if (mog > INF)
                    mog = INF;
            }
            else
                mog = INF;
        }
        ind++;
    }
    ans = (ans % MOD + MOD) %MOD;
    printf ("%lld\n", ans);
    for (int i = 1; i <= n; i++)
        a[i] = b[i] = 0;
}

main()
{
    //ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}