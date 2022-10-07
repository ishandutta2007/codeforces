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

int n, m;
string S;

void solve () {
    cin >> n >> m >> S;
    S = "#" + S;
    vector < int > V;
    int cnt = 0, ans = m, ok = 0;
    for (int i = 1; i <= n; i++){
        if (S[i] == 'W'){
            ok = 1;
            ans++;
            if (cnt){
                V.pb (cnt);
                cnt = 0;
            }
            continue;
        }
        cnt += ok;
    }
    if (ans >= n){
        cout << n*2-1 << endl;
        return;
    }
    sort (V.begin(), V.end());
    ans = ans * 2 - (int)V.size()-1;
    for (int x : V){
        if (x > m)
            break;
        m -= x;
        ans++;
    }
    if (ans > n*2-1)
        ans = n*2-1;
    if (ans < 0)
        ans = 0;
    cout << ans << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        solve ();
    }
}