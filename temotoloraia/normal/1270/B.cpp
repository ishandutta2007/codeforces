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
/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 1000005;

int n;
int a[N];

main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int l = 0, r = 0;
        for (int i = 1; i < n; i++)
            if (abs (a[i] - a[i + 1]) > 1)
                 l = i, r = i + 1;
        if (l == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl << l << " " << r << endl;
    }
}