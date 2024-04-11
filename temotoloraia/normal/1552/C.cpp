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

const int N = 100005, MOD = 1e9+7;

int n, k;
bool F[N];
int x[N], y[N];

void solve () {
    cin >> n >> k;
    for (int i = 1; i <= n*2; i++)
        F[i] = 0;
    for (int i = 1; i <= k; i++){
        cin >> x[i] >> y[i];
        if (x[i] > y[i])
            swap (x[i], y[i]);
        F[x[i]] = F[y[i]] = 1;
    }
    vector < int > V;
    for (int i = 1; i <= n*2; i++){
        if (F[i] == 0)
            V.pb (i);
    }
    for (int i = 0; i < n-k; i++){
        x[i+k+1] = V[i];
        y[i+k+1] = V[i + n - k];
    }
    int ans = 0, p = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++){
            p = 0;
            if (x[i] <= x[j] && x[j] <= y[i])
                p++;
            if (x[i] <= y[j] && y[j] <= y[i])
                p++;
            if (p == 1)
                ans++;
        }
    cout << ans << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin >> T;
    while (T--){
        solve ();
    }
}