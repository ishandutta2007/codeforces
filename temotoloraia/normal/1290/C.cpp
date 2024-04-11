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

const int N = 300005, MOD = 1e9 + 7;

int n, k;

vector < int > v[N];
vector < int > A[2][N];
int a[N];
int md[N], f[N], pas[N];

string S;

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> S;
    S = "#" + S;
    for (int i = 1; i <= k; i++){
        int nn;
        cin >> nn;
        while (nn--){
            int x;
            cin >> x;
            v[x].pb (i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; i++){
        A[0][i].pb (i);
        a[i] = -1;
        md[i] = i;
        f[i] = 0;
    }
    for (int i = 1; i <= n; i++){
        if ((int)v[i].size() == 0){
            cout << ans << endl;
            continue;
        }
        if ((int)v[i].size() == 1){
            int I = v[i][0];
            int ind = md[I];
            int x = f[I];
            if (S[i] == '1')
                x ^= 1;
            ans -= pas[ind];
            pas[ind] = (int)A[x][ind].size();
            ans += pas[ind];
            a[ind] = x;
            cout << ans << endl;
            continue;
        }
        int x = v[i][0], y = v[i][1];
        int t = f[x] ^ f[y];
        if (S[i] == '0')
            t ^= 1;
        x = md[x];
        y = md[y];
        if (x == y){
            cout << ans << endl;
            continue;
        }
        if ((int)A[0][x].size() + (int)A[1][x].size() > (int)A[0][y].size() + (int)A[1][y].size())
            swap (x, y);
        for (int X : A[0][x]){
            f[X] ^= t;
            md[X] = y;
            A[t][y].pb (X);
        }
        for (int X : A[1][x]){
            f[X] ^= t;
            md[X] = y;
            A[1 - t][y].pb (X);
        }
        if (a[x] != -1)
            a[y] = (a[x] ^ t);
        ans -= pas[x] + pas[y];
        pas[x] = 0;
        pas[y] = 0;
        if (a[y] != -1)
            pas[y] = (int)A[a[y]][y].size();
        else
            pas[y] = min ((int)A[0][y].size(), (int)A[1][y].size());
        ans += pas[y];
        cout << ans << endl;
    }
    return 0;
}