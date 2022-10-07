#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

//#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 200005, MOD = 1e9 + 7, INF = 1e11;

int n;
int B[N];
int a[100];

void solve () {
    cin >> n;
    for (int x, y, i = 1; i <= n; i++){
        cin >> x;
        y = 0;
        while (x % 2 == 0){
            x /= 2;
            y++;
        }
        a[y]++;
    }
    int ans = B[n] - 1, sum = 0;
    for (int i = 30; i >= 1; i--){
        if (a[i]){
            int x = B[a[i]-1+sum];
            ans = (ans - x+MOD) % MOD;
        }
        sum += a[i];
    }
    cout << ans << endl;
    for (int i = 0; i <= 40; i++)
        a[i] = 0;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    B[0] = 1;
    for (int i = 1; i < N; i++)
        B[i] = B[i-1] * 2 % MOD;
    int T=1;
    //cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}