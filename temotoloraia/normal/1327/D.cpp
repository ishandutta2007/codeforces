#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
//#define ll long long
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
/*
#pragma comment(linker, "/STACK: 20000000005")
*/


using namespace std;

int solve (vector < int > v){
    int n = v.size();
    for (int X = 1; X < n; X++){
        if (n % X != 0)
            continue;
        for (int i = 0; i < X; i++){
            bool ok = 1;
            for (int j = i; j + X < n; j += X)
                if (v[j + X] != v[j])
                    ok = 0;
            if (ok)
                return X;
        }
    }
    return n;
}

const int N = 200005, MOD = 998244353;

int n;
int c[N], a[N];
bool F[N];

main()
{
    ios_base::sync_with_stdio(0);
    int tes;
    cin >> tes;
    while (tes--){
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        for (int i = 1; i <= n; i++)
            F[i] = 0;
        int ans = n;
        for (int I = 1; I <= n; I++){
            if (F[I])
                continue;
            vector < int > v;
            int x = I;
            v.pb (c[x]);
            x = a[x];
            F[I] = 1;
            while (x != I){
                F[x] = 1;
                v.pb (c[x]);
                x = a[x];
            }
            int nn = solve (v);
            ans = min (ans, nn);
        }
        cout << ans << endl;
    }
    return 0;
}