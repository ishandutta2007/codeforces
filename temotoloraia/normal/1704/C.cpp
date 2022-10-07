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

const int N = 300005, MOD = 1e9 + 7, INF = 1e11;

int m,n;
int a[N];

void solve () {
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort (a+1, a+n+1);
    int ans = n;
    vector < int > V;
    for (int i = 1; i < n; i++)
        V.pb (a[i+1] - a[i] - 1);
    V.pb (a[1] - 1 + m - a[n]);
    sort (V.begin(), V.end());
    reverse (V.begin(), V.end());
    int cnt = 0;
    for (int x, i = 0; i < V.size(); i++){
        x = V[i] - cnt * 2;
        if (x <= 0){
            ans += V[i];
            continue;
        }
        ans += cnt * 2;
        if (x == 1){
            cnt++;
            continue;
        }
        else {
            ans++;
            cnt++;
            if (x >= 3)
                cnt++;
        }
    }
    cout << ans << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}