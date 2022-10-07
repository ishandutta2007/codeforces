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
#define int long long

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

const int N = 200005, MOD = 998244353;

int n, k;
int a[N];
int ans = 1;
int nn = 1;
int sum;
int ok;

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    k = n - k + 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] < k){
            nn += ok;
            continue;
        }
        ok = 1;
        sum += a[i];
        ans = ans * nn % MOD;
        nn = 1;
    }
    cout << sum << " " << ans << endl;
    return 0;
}