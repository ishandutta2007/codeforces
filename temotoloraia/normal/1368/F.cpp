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

const int N = 200005;

int n;
int a[N];

int S;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    S = sqrt (n);
    while (1){
        vector < int > V;
        for (int i = 1; i < n; i++){
            if (i % S == 0 || a[i])
                continue;
            V.pb (i);
            a[i] = 1;
        }
        int k = (int)V.size();
        cout << k << " ";
        for (int x : V)
            cout << x << " ";
        cout << endl;
        int x;
        cin >> x;
        bool ok = 1;
        for (int t, i = x; i < x+k; i++){
            t = (i-1)%n+1;
            if (a[t])
                a[t] = 0;
            else
                ok = 0;
        }
        if (ok){
            cout << 0 << endl;
            break;
        }
    }
}