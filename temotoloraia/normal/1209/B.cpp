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

const int N = 100005, M = 100005;

int n;
int mas[N];
int a[N], b[N];
int ans, pas;

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        char ch;
        cin >> ch;
        mas[i] = ch - '0';
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for (int I = 0; I <= 100000; I++){
        pas = 0;
        for (int i = 1; i <= n; i++){
            if (b[i] == I){
                mas[i] = 1 - mas[i];
                b[i] += a[i];
            }
            pas += mas[i];
        }
        ans = max (ans, pas);
    }
    cout << ans << endl;
    return 0;
}