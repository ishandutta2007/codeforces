#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long int
#define int long long int
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

int F (int a, int b){
    return a - b * b * 3 + b * 3;
}

const int N = 200005, INF = 4e18;

int n, k;
int a[N];
int b[N];
bool ok = 0;
int check (int X){
    int ans = 0;
    for (int d, D, i = 1; i <= n; i++){
        if (a[i] < X)
            continue;
        d = F (a[i], a[i]);
        if (d >= X){
            ans += a[i];
            continue;
        }
        D = (a[i] - X) * 4 / 3 + 1;
        d = sqrt (D);
        d = (d + 1) / 2;
        if (d > a[i])
            d = a[i];
        if (d > 0)
            ans += d;
    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int L = -INF, R = INF;
    while (L < R){
        int MID = L + R + 1 >> 1;
        if (check (MID) >= k)
            L = MID;
        else
            R = MID - 1;
    }
    int X = L;
    int pas = check (L) - k;
    for (int d, D, i = 1; i <= n; i++){
        if (a[i] < X){
            cout << 0 << " ";
            continue;
        }
        d = F (a[i], a[i]);
        if (d > X){
            cout << a[i] << " ";
            continue;
        }
        D = (a[i] - X) * 4 / 3 + 1;
        d = sqrt (D);
        d = (d + 1) / 2;
        if (d > a[i])
            d = a[i];
        if (d < 1){
            cout << 0 << " ";
            continue;
        }
        if (F (a[i], d) > X){
            cout << d << " ";
            continue;
        }
        if (pas){
            pas--;
            d--;
        }
        cout << d << " ";
    }
}