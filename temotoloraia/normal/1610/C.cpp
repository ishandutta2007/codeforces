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

const int N = 200005, MOD = 1e9 + 7, INF = 1e11;

int n;
int a[N], b[N];

bool check (int X){
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (cnt <= a[i] && X - cnt - 1 <= b[i])
            cnt++;
    }
    if (cnt >= X)
        return 1;
    return 0;
}

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i] >> a[i];
    int l = 0, r = n;
    while (l < r){
        int mid = l + r + 1 >> 1;
        if (check (mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
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