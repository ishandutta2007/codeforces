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

const ll MAXN = 200005;

ll n;
ll mas[MAXN];
ll a[MAXN], b[MAXN];
ll ans, pas;


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        a[i] = x;
        ll y = 0;
        while (x % 2 == 0){
            y++;
            x /= 2;
        }
        mas[y]++;
        b[i] = y;
    }
    for (int i = 0; i < 1000; i++){
        if (ans > n - mas[i]){
            pas = i;
            ans = n - mas[i];
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (b[i] != pas)
            cout << a[i] << " ";
    return 0;
}