#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
//#define int long long
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

const int N = 1000005, MOD = 1e9+7;

int n, m;
int dp[N];
int x[N], y[N], t[N];

void solve () {
    cin >> m >> n;
    for (int i = 1; i <= n; i++){
        cin >> t[i] >> x[i] >> y[i];
    }
    dp[0] = x[0] = y[0] = 1;
    int pas = -1;
    for (int i = 1; i <= n; i++){
        if (i >= 1000)
            pas = max (pas, dp[i-1000]);
        dp[i] = pas + 1;
        int qd = max (0, i-1000);
        for (int dis, j = qd; j < i; j++){
            if (dp[j] == 0)
                continue;
            dis = abs (x[i] - x[j]) + abs (y[i] - y[j]);
            if (dis <= t[i] - t[j])
                dp[i] = max (dp[i], dp[j] + 1);
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = max (ans, dp[i]);
    cout << ans-1 << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    //cin >> T;
    while (T--){
        solve ();
    }
}