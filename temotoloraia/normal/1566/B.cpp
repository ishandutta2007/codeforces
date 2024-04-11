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
    string s;
    cin >> s;
    int n = (int)s.size();
    int a[2] = {0, 0};
    for (int i = 0; i < n; i++)
        a[s[i]-'0'] = 1;
    if (a[0] == 0){
        cout << 0 << endl;
        return;
    }
    if (a[1] == 0){
        cout << 1 << endl;
        return;
    }
    int ans = 0;
    s += "1";
    for (int i = 0; i < n; i++)
        if (s[i] != s[i+1])
            ans++;
    if (ans <= 2)
        cout << 1 << endl;
    else
        cout << 2 << endl;
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