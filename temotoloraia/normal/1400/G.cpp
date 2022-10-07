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

const int N = 300005, MOD = 998244353;

int n, m;
int l[N], r[N];
int u[N], v[N];
bool F[N];
int K;

int M[N];
vector < int > g[N], V;

void dfs (int x){
    if (F[x])
        return;
    if (K < l[x] || r[x] < K)
        return;
    V.pb (x);
    M[x] = (int)V.size();
    F[x] = 1;
    for (int y : g[x])
        dfs (y);
}

int mas[N];
int dp[1000], D[1000];
int bit[N];
int FA[N], inv[N];

int C (int x, int y){
    if (x < y)
        return 0;
    return FA[x] * inv[y] % MOD * inv[x-y] % MOD;
}

void solve () {
    scanf ("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf ("%lld%lld", &l[i], &r[i]);
    vector < int > ca;
    for (int i = 1; i <= m; i++){
        scanf ("%lld%lld", &u[i], &v[i]);
        g[u[i]].pb (v[i]);
        g[v[i]].pb (u[i]);
        ca.pb (u[i]);
        ca.pb (v[i]);
    }
    for (int i = 1; i <= n; i++){
        if ((int)g[i].size() > 0)
            continue;
        mas[l[i]]++;
        mas[r[i]+1]--;
    }
    int ANS = 0;
    for (K = 1; K <= n; K++){
        mas[K] += mas[K-1];
        for (int i = 1; i <= m; i++)
            F[u[i]] = F[v[i]] = 0;
        for (int i = 0; i <= m*2; i++)
            dp[i] = 0;
        dp[0] = 1;
        int nn = 0;
        for (int x : ca){
            V.clear();
            for (int i = 1; i <= m; i++)
                M[u[i]] = M[v[i]] = 0;
            dfs (x);
            if ((int)V.size() == 0)
                continue;
            int np = (int)V.size();
            for (int i = 0; i < np; i++)
                bit[i] = (1 << np) - 1;
            for (int i = 1; i <= m; i++){
                int x = M[u[i]], y = M[v[i]];
                if (x == 0 || y == 0)
                    continue;
                x--;
                y--;
                bit[x] ^= (1 << y);
                bit[y] ^= (1 << x);
            }
            for (int i = 0; i <= nn + np; i++)
                D[i] = 0;
            for (int bx, cnt, B = 0; B < (1 << np); B++){
                bx = (1 << np) - 1;
                cnt = 0;
                for (int i = 0; i < np; i++){
                    if (B & (1 << i)){
                        bx &= bit[i];
                        cnt++;
                    }
                }
                if ((bx & B) != B)
                    continue;
                for (int i = 0; i <= nn; i++)
                    D[i+cnt] += dp[i];
            }
            nn += np;
            for (int i = 0; i <= nn; i++){
                dp[i] = (D[i] % MOD);
                D[i] = 0;
            }
        }
        for (int i = 0; i <= nn && i <= K; i++){
            ANS += dp[i] * C (mas[K], K - i);
            ANS %= MOD;
        }
    }
    cout << ANS << endl;
}

int POWER (int x, int y){
    int ans = 1;
    while (y){
        if (y & 1)
            ans = ans * x % MOD;
        y >>= 1;
        x = x * x % MOD;
    }
    return ans;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //freopen ("sequence.in", "r", stdin);freopen ("sequence.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    FA[0] = inv[0] = 1;
    for (int i = 1; i <= 300000; i++){
        FA[i] = FA[i-1] * i % MOD;
        inv[i] = POWER (FA[i], MOD-2);
    }
    int T=1;
    //cin >> T;
    while (T--)
        solve ();
}