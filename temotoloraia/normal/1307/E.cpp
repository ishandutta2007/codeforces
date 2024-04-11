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

const int N = 5005, MOD = 1e9 + 7;

int n, m;
int s[N];
int a[N], b[N];
int x[N], y[N];

int V[N][5];
int ans, RAD;

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= m; i++){
        cin >> a[i] >> b[i];
        int t = 0;
        x[i] = n + 1;
        for (int j = 1; j <= n; j++){
            if (s[j] == a[i])
                t++;
            if (t == b[i]){
                x[i] = j;
                break;
            }
        }
        t = 0;
        for (int j = n; j >= 1; j--){
            if (s[j] == a[i])
                t++;
            if (t == b[i]){
                y[i] = j;
                break;
            }
        }
    }
    for (int I = 0; I <= n; I++){
        bool ok = 0;
        for (int i = 0; i <= m; i++)
            if (x[i] == I)
                ok = 1;
        if (ok == 0)
            continue;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 4; j++)
                V[i][j] = 0;
        for (int i = 1; i <= m; i++){
            int t = 0;
            if (x[i] == I){
                V[a[i]][0]++;
                continue;
            }
            if (x[i] <= I)
                t += 1;
            if (y[i] > I)
                t += 2;
            if (t)
                V[a[i]][t]++;
        }
        int pas = 0, rad = 1;
        int nn, MX, mx, C;
        for (int i = 1; i <= n; i++){
            if (V[i][0]){
                pas++;
                nn = V[i][2] + V[i][3];
                if (nn > 0){
                    pas++;
                    rad = rad * nn % MOD;
                }
                continue;
            }
            if (V[i][1] + V[i][2] + V[i][3] == 0)
                continue;
            MX = 1;
            C = 0;
            if (V[i][1] > 0 && V[i][2] + V[i][3] > 0)
                MX = 2;
            if (V[i][1] + V[i][3] > 0 && V[i][2] > 0)
                MX = 2;
            if (V[i][3] > 1)
                MX = 2;
            pas += MX;
            if (MX == 1){
                C = V[i][1] + V[i][2] + 2 * V[i][3];
                rad = rad * C % MOD;
                continue;
            }
            C += V[i][1] * (V[i][2] + V[i][3]);
            C += V[i][3] * (V[i][2] + V[i][3] - 1);
            C %= MOD;
            rad = rad * C % MOD;
        }
        if (pas == ans)
            RAD = (RAD + rad) % MOD;
        if (pas > ans){
            ans = pas;
            RAD = rad;
        }
    }
    cout << ans << " " << RAD << endl;
    return 0;
}