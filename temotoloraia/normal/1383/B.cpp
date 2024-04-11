#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll __int128
//#define ll long long
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

void solve () {
    cin >> n;
    int X = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        X ^= a[i];
    }
    if (X == 0){
        cout << "DRAW" << endl;
        return;
    }
    int Y = 1;
    while (Y * 2 <= X)
        Y *= 2;
    int p = 0, q = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] & Y)
            p++;
        else
            q ^= 1;
    }
    if (q == 0){
        if (p % 4 == 1){
            cout << "WIN" << endl;
        }
        else
            cout << "LOSE" << endl;
        return;
    }
    if (p % 4 == 3)
        cout << "WIN" << endl;
    else
        cout << "WIN" << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve ();
}