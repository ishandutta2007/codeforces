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
/*
#pragma GCC optimize ("O3")

//#pragma comment(linker, "/STACK: 20000000005")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
*/
using namespace std;


const ll N = 100005, MOD = 998244353;

ll np, mas[65];
ll mass[N];

map < string, bool > S;

ll M[12][65][65];

ll D[65][65][65];

ll n, x, y, z;

int m, a, b, c, d;

int main()
{
    //freopen ("in.txt", "r", stdin);freopen ("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    for (char ch = 'a'; ch <= 'z'; ch++){
        mas[++np] = ch;
        mass[ch] = np;
    }
    for (char ch = 'A'; ch <= 'Z'; ch++){
        mas[++np] = ch;
        mass[ch] = np;
    }
    for (char ch = '0'; ch <= '9'; ch++){
        mas[++np] = ch;
        mass[ch] = np;
    }
    scanf ("%d", &n);
    char ch;
    ch = getchar();
    string s, ss;
    while (n--){
        s = "";
        while (1){
            ch = getchar();
            if (ch == '\n')
                break;
            s += ch;
        }
        if (S[s])
            continue;
        S[s] = 1;
        m = (int)s.size();
        x = s[0], y = s[m - 1];
        x = mass[x];
        y = mass[y];
        ++M[m][x][y];
        ss = "";
        for (int i = m - 1; i >= 0; i--)
            ss += s[i];
        if (S[ss])
            continue;
        S[ss] = 1;
        ++M[m][y][x];
    }
    ll ans = 0;
    for (m = 3; m <= 10; ++m){
        for (a = 1; a <= np; ++a)
        for (b = 1; b <= np; ++b)
        for (c = 1; c <= np; ++c)
        D[a][b][c] = 0;
        for (d = 1; d <= np; ++d)
            for (a = 1; a <= np; ++a){
                x = M[m][a][d];
                if (x)
                    for (b = 1; b <= np; ++b){
                        y = x * M[m][b][d];
                        if (y)
                            for (c = 1; c <= np; ++c){
                                z = y * M[m][c][d] % MOD;
                                D[a][b][c] += z;
                            }
                    }
                }
        for (a = 1; a <= np; ++a)
        for (b = 1; b <= np; ++b)
        for (c = 1; c <= np; ++c)
        D[a][b][c] %= MOD;
        ll pas = 0;
        for (a = 1; a <= np; ++a)
        for (b = a; b <= np; ++b)
        for (c = b; c <= np; ++c)
        if (D[a][b][c])
        for (d = c; d <= np; ++d){
            x = D[a][b][c] * D[a][b][d] % MOD * D[a][c][d] % MOD * D[b][c][d] % MOD;
            y = 24;
            if (a == d){
                y = 1;
            }
            else if (a == c || b == d){
                y = 4;
            }
            else if (b == c){
                y = 12;
            }
            else if (a == b && c == d){
                y = 6;
            }
            else if (a == b || c == d){
                y = 12;
            }
            ans += x * y;
        }
        ans %= MOD;
    }
    printf ("%lld\n", ans);
    return 0;
}