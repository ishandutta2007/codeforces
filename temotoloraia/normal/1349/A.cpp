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

const int N = 200000;

int n;
int a[N], b[N];
vector < int > V[N + 5];
int ans=1;
map < int, bool > M;

void ad (int p){
    for (int i = 1; i <= n; i++){
        int x = a[i];
        while (x % p == 0){
            x /= p;
        }
        b[i] = a[i] / x;
    }
    sort (b+1, b+n+1);
    ans *= b[2];
}

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector < int > P;
    for (int p : V[a[1]]){
        if (M[p])
            continue;
        M[p] = 1;
        ad (p);
    }
    for (int p : V[a[2]]){
        if (M[p])
            continue;
        M[p] = 1;
        ad (p);
    }
    cout << ans << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 2; i <= N; i++){
        if (V[i].size() > 0)
            continue;
        for (int j = i; j <= N; j += i)
            V[j].pb (i);
    }
    int T=1;
    //cin >> T;
    while (T--)
        solve();
}