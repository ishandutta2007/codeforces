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

const int N = 100005;

int n, m;
int s[N];
pair < int, int > P[N];

void solve () {
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> P[i].F >> P[i].S;
    sort (P + 1, P + n + 1);
    reverse (P + 1, P + n + 1);
    int mx = 0, ans = 0;
    for (int i = 1; i <= n; i++){
        s[i] = s[i-1] + P[i].F;
        mx = max (mx, P[i].S);
        if (i <= m)
            ans = max (ans, s[i] + (m - i) * mx);
    }
    for (int i = 1; i <= n; i++){
        if (P[i].F >= P[i].S)
            continue;
        int l = 0, r = n;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (P[mid].F > P[i].S)
                l = mid;
            else
                r = mid - 1;
        }
        if (l+1 > m)
            continue;
        ans = max (ans, s[l] + P[i].F + P[i].S * (m - l - 1));
    }
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