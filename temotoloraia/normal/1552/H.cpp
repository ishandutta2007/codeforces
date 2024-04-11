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

const int N = 200, MOD = 998244353;

int a[N+5];

void mak (int x){
    vector < int > V;
    for (int i = x; i <= 200; i += x)
        V.pb (i);
    cout << "? " << (int)V.size() * 200 << endl;
    for (int i = x; i <= 200; i += x)
        for (int j = 1; j <= 200; j++)
            cout << i << " " << j << " ";
    cout << endl;
    cin >> a[x];
}
int n, m;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    mak (1);
    int S = a[1];
    int l = 0, r = 7;
    while (l < r){
        int mid = (l + r + 1>> 1);
        int B = (1 << mid);
        mak (B);
        if (a[B] * B == S)
            l = mid;
        else
            r = mid - 1;
    }
    if (l == 7){
        n = (1 << 7);
        m = S / n;
        cout << "! " << 2 * (n + m - 2) << endl;
        return 0;
    }
    int B = (1 << l);
    int C = B*2;
    if (a[C] * C < S){
        int x = a[1] - a[C] * C;
        int p = B * a[C] / x;
        n = p * C + B;
    }
    else {
        int x = a[C] * C - a[1];
        int p = B * a[C] / x;
        n = p * C - B;
    }
    m = S / n;
    cout << "! " << 2 * (n + m - 2) << endl;
}