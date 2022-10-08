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

const int N = 100005, MOD = 1e9+7;

int n, k;
int last[N], a[N];
bool F[N];
int A[N], B[N];

void solve () {
    cin >> n >> k;
    int MX = (n + k - 2) / (k - 1);
    for (int i = 1; i <= n*k; i++)
        a[i] = 0;
    for (int i = 1; i <= n; i++){
        last[i] = 0;
        F[i] = 0;
    }
    for (int x, i = 1; i <= n*k; i++){
        cin >> x;
        if (F[x])
            continue;
        if (last[x] == 0){
            last[x] = i;
            continue;
        }
        int mx = a[last[x]];
        for (int j = last[x]+1; j < i; j++)
            mx = max (mx, a[j]);
        if (mx < MX){
            A[x] = last[x];
            B[x] = i;
            for (int j = last[x]; j < i; j++)
                a[j]++;
            F[x] = 1;
        }
        last[x] = i;
    }
    for (int i = 1; i <= n; i++){
        cout << A[i] << " " << B[i] << endl;
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin >> T;
    while (T--){
        solve ();
    }
}