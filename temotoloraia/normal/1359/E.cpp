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

const int N = 5e5 + 5, MOD = 998244353;

int POWER (int x, int y){
    int ans = 1;
    while (y){
        if (y & 1)
            ans = ans * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ans;
}

int F[N], inv[N];

int C (int n, int k){
    if (n < k)
        return 0;
    return F[n] * inv[k] % MOD * inv[n-k] % MOD;
}

int n, k;

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    F[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++){
        F[i] = F[i-1] * i % MOD;
        inv[i] = POWER (F[i], MOD-2);
    }
    int ans = 0;
    for (int x = 1; x <= n; x++){
        int nn = n / x - 1;
        ans = (ans + C (nn, k-1)) % MOD;
    }
    cout << ans << endl;
}