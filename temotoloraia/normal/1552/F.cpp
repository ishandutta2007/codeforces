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

int n;
int x[N], y[N];
bool ch[N];
set < pair < int, int > > S;
int sum[N], ans[N];

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i] >> ch[i];
        S.insert ({x[i], i});
    }
    for (int i = 1; i <= n; i++){
        auto it = S.upper_bound ({y[i], 0});
        int id = (*it).S;
        ans[i] += x[i] - y[i];
        ans[i] += sum[i-1] - sum[id - 1];
        ans[i] = (ans[i]%MOD + MOD) % MOD;
        sum[i] = (sum[i-1] + ans[i]) % MOD;
    }
    int ANS = (x[n] + 1)% MOD;
    for (int i = 1; i <= n; i++)
        if (ch[i])
            ANS = (ANS + ans[i]) % MOD;
    cout << ANS << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin >> T;
    while (T--){
        solve ();
    }
}