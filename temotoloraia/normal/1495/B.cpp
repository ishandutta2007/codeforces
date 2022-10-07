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

const int N = 200005, MOD = 1e9+7;

int n;
int p[N];
int a[N], b[N];

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    a[1] = 1;
    for (int i = 2; i <= n; i++){
        a[i] = 1;
        if (p[i] > p[i-1])
            a[i] = 1 + a[i-1];
    }
    b[n] = 1;
    for (int i = n-1; i >= 1; i--){
        b[i] = 1;
        if (p[i] > p[i+1])
            b[i] = 1 + b[i+1];
    }
    int mx = 0;
    for (int i = 1; i <= n; i++){
        mx = max (mx, a[i]);
        mx = max (mx, b[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] == mx)
            cnt++;
        if (b[i] == mx)
            cnt++;
    }
    if (cnt != 2){
        cout << 0 << endl;
        return;
    }
    if (mx % 2 == 0){
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == mx && b[i] == mx)
            ans++;
    cout << ans << endl;
}

main()
{
  //  freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
   // cin >> T;
    while (T--){
        solve ();
    }
}