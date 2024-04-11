#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122


#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
/*
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 2e5 + 5;

ll n;
ll a[N];
ll b[N];

ll x, y, A, B, K;


bool check (ll t){
    for (int i = 1; i <= n; i++)
        b[i] = 0;
    for (int i = A; i <= t; i += A)
        b[i] += x;
    for (int i = B; i <= t; i += B)
        b[i] += y;
    ll sum = 0;
    sort (b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        sum += a[i] * b[i];
    if (sum >= K)
        return 1;
    return 0;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int Q;
    cin >> Q;
    while (Q--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            a[i] /= 100;
        }
        sort (a + 1, a + n + 1);
        cin >> x >> A >> y >> B >> K;
        int l = 1, r = n + 1;
        while (l < r){
            int mid = l + r >> 1;
            if (check (mid))
                r = mid;
            else
                l = mid + 1;
        }
        if (l > n)
            l = -1;
        cout << l << endl;
    }
    return 0;
}