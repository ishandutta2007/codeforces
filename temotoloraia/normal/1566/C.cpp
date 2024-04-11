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

const int N = 1000005, MOD = 1e9 + 7;

void solve () {
    int n;
    string A, B;
    cin >> n >> A >> B;
    int ans = 0, x = 0, y = 0;
    for (int i = 0; i < n; i++){
        if (A[i] != B[i]){
            ans += 2;
            if (x){
                ans++;
                x = 0;
            }
            y = 0;
            continue;
        }
        if (A[i] == '0'){
            if (x){
                ans++;
            }
            x = 1;
        }
        else
            y = 1;
        if (x + y == 2){
            ans += 2;
            x = y = 0;
        }
    }
    if (x)
        ans++;
    cout << ans << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}