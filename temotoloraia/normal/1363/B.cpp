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

const int N = 100005, MOD = 998244353;


int a[N];

void solve () {
    string S;
    cin >> S;
    int n = S.size();
    if (n == 1){
        cout << 0 << endl;
        return;
    }
    S = "#" + S;
    for (int i = 1; i <= n; i++)
        a[i] = a[i-1] + S[i] - '0';
    int ans = n;
    for (int i = 1; i < n; i++){
        int x = a[i], y = a[n] - a[i];
        int pas = min (x, i-x) + min (y, n-i-y);
        ans = min (ans, pas);
    }
    cout << ans << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        solve ();
    }
}