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

//#define int long long
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

const int N = 1000005, M = 3e6;
const double INF = 1e9;

int n;
double a[N];
int zoma[N];
double A, B, C;
double X, T;

priority_queue < pair < int, double > > Q;

main()
{
    //ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        scanf ("%d", &x);
        a[i] = x;
    }
    for (int i = 1; i <= n; i++)
        zoma[i] = 1;
    Q.push ({-n, a[n]});
    for (int I = n - 1; I >= 1; I--){
        double sa = a[I];
        int num = 1;
        while (Q.size() > 0){
            T = Q.top().S;
            if (T >= sa)
                break;
            A = num;
            B = zoma[-Q.top().F];
            num += zoma[-Q.top().F];
            zoma[-Q.top().F] = 0;
            C = A + B;
            X = (A / C * sa) + (B / C * T);
            sa = X;
            Q.pop();
        }
        zoma[I] = num;
        a[I] = sa;
        Q.push ({-I, sa});
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j < i + zoma[i]; j++)
            a[j] = a[i];
    for (int i = 1; i <= n; i++)
        printf ("%.10f\n", a[i]);
    return 0;
}