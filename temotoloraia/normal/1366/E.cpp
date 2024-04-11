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

const int N = 500005, MOD = 998244353;

int n, m;
int a[N], b[N];
int ans[N];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = n; i >= 1; i--)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    int mx = a[1] + 1, ind = m;
    for (int i = 1; i <= n; i++){
        mx = min (mx, a[i]);
        while (b[ind] > mx)
            ind--;
        if (b[ind] == mx)
            ans[ind]++;
    }
    if (mx != b[1]){
        cout << 0 << endl;
        return 0;
    }
    if (ans[1] > 1)
        ans[1] = 1;
    int ANS = 1;
    for (int i = 1; i <= m; i++)
        ANS = ANS * ans[i] % MOD;
    cout << ANS << endl;
}