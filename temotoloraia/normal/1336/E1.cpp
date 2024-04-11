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

int F (int x){
    int y = 0;
    while (x){
        if ((x & 1))
            y++;
        x >>= 1;
    }
    return y;
}

const int N = 2000005, MOD = 998244353;

int nn, m;
int rad, R = 1;
int ans[N];
int n, a[N];
int mas[N];
int B[N];
unordered_map < int, int > M;
int DP[40][100005];

main()
{
    ios_base::sync_with_stdio(0);
    cin >> nn >> m;
    while (nn--){
        int x;
        cin >> x;
        for (int i = 1; i <= n; i++){
            if ((x ^ a[i]) < x)
                x ^= a[i];
        }
        if (x == 0)
            rad++;
        else {
            a[++n] = x;
            //sort (a + 1, a + n + 1);
            //reverse (a + 1, a + n + 1);
        }
    }
    nn=0;
    sort (a + 1, a + n + 1);
    while (rad--)
        R = R * 2 % MOD;
    if (n <= 20){
        mas[1] = 0;
        nn = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= nn; j++)
                mas[nn + j] = (mas[j] ^ a[i]);
            nn *= 2;
        }
        for (int i = 1; i <= nn; i++)
            ans[F (mas[i])]++;
        for (int i = 0; i <= m; i++){
            ans[i] = ans[i] * R % MOD;
            cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    bool OK = 0;
    if (m == 36)
        OK = 1;
    for (int I = 0; I < 2000; I++){
        for (int j = 2; j <= n; j++)
            for (int i = j - 1; i >= 1; i--)
                if ((a[i] ^ a[j]) < a[j])
                    a[j] ^= a[i];
    }
    for (int j = 2; j <= n; j++)
        for (int i = j - 1; i >= 1; i--)
            if ((a[i] ^ a[j]) < a[i])
                assert (0);
    B[0] = 1;
    for (int i = 1; i <= 60; i++)
        B[i] = B[i - 1] * 2;
    int A = 0;
    for (int i = 0; i < m; i++){
        bool ok = 0;
        for (int j = 1; j <= n; j++)
            if (B[i] <= a[j] && a[j] < B[i + 1])
                ok = 1;
        if (ok == 0)
            A += B[i];
    }
    for (int i = 1; i <= n; i++){
        a[i] = (a[i] & A);
        if (OK)
            cout << a[i] << " ";
    }
    if (OK)
        cout << endl << A << endl;
    for (int x = A; x > 0; x = ((x - 1) & A)){
        mas[++nn] = x;
        M[x] = nn;
    }
    mas[++nn] = 0;
    M[0] = nn;
    if (OK)
        cout << M[7] << " " << n  << " " << nn << endl;
    DP[0][nn] = 1;
    int x;
    for (int i = 1; i <= n; i++){
        for (int j = i - 1; j >= 0; j--){
            for (int k = 1; k <= nn; k++){
                x = (a[i] ^ mas[k]);
                x = M[x];
                DP[j+1][x] += DP[j][k];
                if (DP[j+1][x] >= MOD)
                    DP[j+1][x] -= MOD;
            }
        }
    }
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= nn; j++){
            x = i + F (mas[j]);
            if (OK == 1 && i == 1 && mas[j] == 7)
                cout << DP[i][j] << " " << x << endl;
            ans[x] += DP[i][j];
            if (ans[x] >= MOD)
                ans[x] -= MOD;
        }
    for (int i = 0; i <= m; i++)
        cout << ans[i] * R % MOD << " ";
    cout << endl;
    return 0;
}