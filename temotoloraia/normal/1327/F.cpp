#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
//#define ll long long
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
/*
#pragma comment(linker, "/STACK: 20000000005")
*/


using namespace std;


const int N = 500005, MOD = 998244353;



int n, m, k;
int l[N], r[N], x[N], a[N];
int mas[N];
int ANS = 1;
int dp[N];

int F[N];
void upd (int x, int y){
    for (int i = x; i <= n; i += i & -i){
        F[i] += y;
        if (F[i] >= MOD)
            F[i] -= MOD;
    }
}

int datvla (int x){
    int pas = 0;
    for (; x > 0; x -= x & -x)
        pas += F[x];
    return pas % MOD;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++)
        cin >> l[i] >> r[i] >> x[i];
    while (k--){
        for (int i = 0; i <= n; i++){
            dp[i] = 0;
            a[i] = 0;
            F[i] = 0;
            mas[i] = 0;
        }
        for (int i = 1; i <= m; i++){
            int t = x[i] % 2;
            x[i] /= 2;
            if (t == 1){
                mas[l[i]]++;
                mas[r[i] + 1]--;
                continue;
            }
            a[r[i]] = max (a[r[i]], l[i]);
        }
        for (int i = 1; i <= n; i++)
            a[i] = max (a[i], a[i - 1]);
        for (int i = 1; i <= n; i++){
            mas[i] += mas[i - 1];
            dp[i] = dp[i - 1];
            if (mas[i] == 0)
                dp[i]++;
        }
        for (int i = 1; i <= n; i++){
            if (a[i] == 0)
                continue;
            if (dp[i] == dp[a[i] - 1])
                ANS = 0;
        }
        for (int i = 0; i <= n; i++){
            dp[i] = 0;
        }
        dp[0] = 1;
        if (mas[1] == 0)
            upd (1, 1);
        for (int i = 1; i <= n; i++){
            dp[i] = datvla (i);
            if (a[i] > 0)
                dp[i] -= datvla (a[i] - 1);
            else
                dp[i]++;
            if (dp[i] < 0)
                dp[i] += MOD;
            if (dp[i] >= MOD)
                dp[i] -= MOD;
            if (mas[i + 1] == 0)
                upd (i + 1, dp[i]);
        }
        ANS = ANS * dp[n] % MOD;
    }
    cout << ANS << endl;
    return 0;
}