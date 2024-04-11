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
int ans[N];

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    ans[n] = 10;
    int X = 81, Y = 180;
    for (int L = n - 1; L >= 1; L--){
        ans[L] = X * (n - L - 1) % MOD + Y;
        ans[L] %= MOD;
        Y = Y * 10 % MOD;
        X = X * 10 % MOD;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}