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

const int N = 300005;

int mas[N];

string str = "codeforces";

void solve () {
    int k;
    cin >> k;
    int n = 1;
    while (mas[n+1] <= k)
        n++;
    for (int x = 10; x >= 0; x--){
        int y = 10 - x;
        int A = 1;
        for (int i = 0; i < x; i++)
            A *= n;
        for (int i = 0; i < y; i++)
            A *= n+1;
        if (A < k)
            continue;
        for (int i = 0; i < 10; i++){
            if (i < x)
                A = n;
            else
                A = n+1;
            while (A--)
                cout << str[i];
        }
        cout << endl;
        return;
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    for (int x = 1; x <= 40; x++){
        mas[x] = 1;
        for (int i = 1; i <= 10; i++)
            mas[x] *= x;
    }
    int T=1;
    //cin >> T;
    while (T--)
        solve ();
}