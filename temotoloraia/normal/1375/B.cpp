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

const int MOD = 998244353;

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

const int N = 1005;

int n, m;
int a[N][N], b[N][N];

void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            b[i][j] = 4;
            if (i == 1)
                b[i][j]--;
            if (i == n)
                b[i][j]--;
            if (j == 1)
                b[i][j]--;
            if (j == m)
                b[i][j]--;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    if (a[i][j] > b[i][j]){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
}


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--){
        solve ();
    }
}