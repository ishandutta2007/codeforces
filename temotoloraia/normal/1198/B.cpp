#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
/*
#pragma GCC optimize ("O3")
#pragma comment(linker, "/STACK: 20000000005")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
*/
using namespace std;

const int N = 500005;

int n, Q;
int a[N], t[N];
int mas[N];

main()
{
    //freopen ("in.txt", "r", stdin);freopen ("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf ("%d", &a[i]);
    cin >> Q;
    for (int I = 1; I <= Q; I++){
        int p;
        scanf ("%d", &p);
        if (p == 2){
            int x;
            scanf ("%d", &x);
            mas[I] = x;
            continue;
        }
        int pos, x;
        scanf ("%d %d", &pos, &x);
        a[pos] = x;
        t[pos] = I;
    }
    for (int i = Q - 1; i >= 0; i--)
        mas[i] = max (mas[i], mas[i + 1]);
    for (int i = 1; i <= n; i++){
        a[i] = max (a[i], mas[t[i]]);
        printf ("%d\n", a[i]);
    }
    cout << endl;
    return 0;
}