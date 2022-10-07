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
#define int long long

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

const int N = 2005, INF = 1e18;

int F (string x, string y){
    int num = 0;
    for (int i = 0; i < 7; i++){
        if (x[i] > y[i])
            return -1;
        if (y[i] > x[i])
            num++;
    }
    return num;
}

string S[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int n, k;
bool dp[N][N];
string a[N];

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[n+1][0] = 1;
    for (int i = n; i >= 1; i--){
        vector < int > v;
        for (int j = 0; j < 10; j++){
            int x = F (a[i], S[j]);
            if (x == -1)
                continue;
            v.pb (x);
        }
        for (int x : v)
            for (int j = 0; j + x <= k; j++){
                if (dp[i + 1][j] == 1)
                    dp[i][j + x] = 1;
            }
    }
    if (dp[1][k] == 0){
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 9; j >= 0; j--){
            int x = F (a[i], S[j]);
            if (x == -1)
                continue;
            if (x > k)
                continue;
            if (dp[i + 1][k - x] == 0)
                continue;
            k -= x;
            cout << j;
            break;
        }
    }
}