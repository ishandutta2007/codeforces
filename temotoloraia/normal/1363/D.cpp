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

const int N = 200005, MOD = 998244353;

int n, k;
int a[N];
int ans[N];

void solve () {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        a[i] = 0;
    for (int i = 1; i <= k; i++){
        int nn;
        cin >> nn;
        while (nn--){
            int x;
            cin >> x;
            a[x] = i;
        }
    }
    int MX, mx;
    cout << "? " << n << " ";
    for (int i = 1; i <= n; i++)
        cout << i << " ";
    cout << endl;
    cin >> MX;
    int l = 1, r = n;
    while (l < r){
        int mid = l + r >> 1;
        cout << "? " << mid - l + 1 << " ";
        for (int i = l; i <= mid; i++)
            cout << i << " ";
        cout << endl;
        cin >> mx;
        if (mx == MX)
            r = mid;
        else
            l = mid + 1;
    }
    for (int i = 1; i <= k; i++)
        ans[i] = MX;
    vector < int > v;
    for (int i = 1; i <= n; i++)
        if (a[i] != a[l])
            v.pb (i);
    cout << "? " << (int)v.size() << " ";
    for (int x : v)
        cout << x << " ";
    cout << endl;
    cin >> ans[a[l]];
    cout << "! ";
    for (int i = 1; i <= k; i++)
        cout << ans[i] << " ";
    cout << endl;
    string s;
    cin >> s;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--){
        solve ();
    }
}