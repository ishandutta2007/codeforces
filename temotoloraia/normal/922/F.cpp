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

const int N = 300000;

vector < int > V[N+5];

bool F[N+5];
int a[N+5];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    for (int i = 1; i <= N; i++)
        for (int j = i*2; j <= N; j += i)
            V[j].pb (i);
    int n=6, k=6;
    cin >> n >> k;
    int T, rad = -k;
    for (T = 1; T <= n; T++){
        F[T] = 1;
        a[T] = (int)V[T].size();
        rad += a[T];
        for (int x : V[T])
            a[x]++;
        if (rad >= 0)
            break;
    }
    if (T > n){
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i <= T; i++){
        if (rad != a[i])
            continue;
        cout << "Yes" << endl;
        cout << T-1 << endl;
        for (int j = 1; j <= T; j++)
            if (i != j)
                cout << j << " ";
        cout << endl;
        return 0;
    }
    for (int i = T; i >= 1; i--){
        if (a[i] > rad)
            continue;
        rad -= a[i];
        a[i] = 0;
        F[i] = 0;
        for (int x : V[i])
            a[x]--;
        for (int x = i*2; x <= T; x++)
            if (F[x])
                a[x]--;
    }
    if (rad){
        cout << "No" << endl;
        return 0;
    }
    rad = 0;
    for (int i = 1; i <= T; i++)
        if (F[i])
            rad++;
    cout << "Yes" << endl;
    cout << rad << endl;
    for (int i = 1; i <= T; i++)
        if (F[i])
            cout << i << " ";
    cout << endl;
    return 0;
}