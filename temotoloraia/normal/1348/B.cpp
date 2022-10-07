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
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/STACK: 20000000005")
*/
using namespace std;

const int N = 5005;
//const int MOD = 1e9+7;
const int MOD = 998244353;

int a[N], b[N], mas[N];

map < int, int > M;

void solve () {
    int n, k;
    cin >> n >> k;
    M.clear();
    int m = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (M[a[i]] == 0){
            mas[++m] = a[i];
            M[a[i]] = m;
        }
    }
    if (m > k){
        cout << -1 << endl;
        return;
    }
    while (m < k){
        mas[++m] = 1;
    }
    cout << n*m << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << mas[j] << " ";
    cout << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--)
        solve();
}