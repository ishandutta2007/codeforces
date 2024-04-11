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

const int N = 3005, INF = 1e18;


int n;
int a[N];
int mas[N];

int D[N][N];

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n+1; j++)
            D[i][j] = 0;
        int sum = 0;
        for (int j = n; j > i; j--){
            D[i][j] = sum;
            if (a[i] == a[j])
                sum++;
        }
        sum = 0;
        for (int j = 1; j < i; j++){
            D[i][j] = sum;
            if (a[i] == a[j])
                sum++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            ans += D[i][j] * D[j][i];
    cout << ans << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //freopen ("sequence.in", "r", stdin);freopen ("sequence.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    while (T--)
        solve ();
}