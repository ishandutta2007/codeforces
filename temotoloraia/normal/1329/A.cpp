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
#define int long long

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

const int N = 100005, MOD = 1e9 + 7;

int m, n;
int a[N];
int b[N];
int sum;

main()
{
    ios_base::sync_with_stdio(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if (sum < m){
        cout << -1 << endl;
        return 0;
    }
    int last = 0;
    for (int i = n; i >= 1; i--){
        if (last == m){
            cout << -1 << endl;
            return 0;
        }
        if (a[i] <= last){
            b[i] = last - a[i] + 2;
            last++;
        }
        else {
            b[i] = 1;
            last = a[i];
        }
    }
    b[0] = m + 1;
    for (int i = 1; i <= n; i++){
        b[i] = max (b[i], b[i - 1] - a[i]);
    }
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
    cout << endl;
    return 0;
}