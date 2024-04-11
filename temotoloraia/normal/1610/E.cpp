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
int a[N];
set < pair < int, int > > A;

void solve () {
    cin >> n;
    A.clear();
    for (int i = 1; i <= n; i++){
        //cin >> a[i];
        scanf ("%lld", &a[i]);
        A.insert ({a[i], i});
    }
    int ANS = 1, cnt = 0;
    for (int i = 1; i < n; i++){
        if (a[i] == a[i+1] && a[i] == a[i+2]){
            cnt++;
            continue;
        }
        int ans = cnt + 2, cur = i+1, x;
        while (cur < n){
            x = a[cur] * 2 - a[i];
            auto it = A.lower_bound ({x, cur+1});
            if (it == A.end())
                break;
            cur = (*it).S;
            ans++;
        }
        ANS = max (ANS, ans);
        cnt = 0;
    }
    cout << n - ANS << endl;
    for (int i = 1; i <= n; i++)
        a[i] = 0;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}