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

const int N = 1005, INF = 1e18 + 3;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

int n, m, T;
char ch[N][N];
int D[N][N];


queue < pair < int, int > > Q;

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> T;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> ch[i][j];
            D[i][j] = INF;
        }
    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= m; c++){
            for (int i = 0; i < 4; i++){
                int newr = r + dr[i], newc = c + dc[i];
                if (newr < 1 || n < newr || newc < 1 || m < newc)
                    continue;
                if (ch[newr][newc] == ch[r][c])
                    D[r][c] = 0;
            }
            if (D[r][c] == 0){
                Q.push ({r, c});
            }
        }
    while (Q.size() > 0){
        int r = Q.front().F, c = Q.front().S;
        Q.pop();
        for (int i = 0; i < 4; i++){
            int newr = r + dr[i], newc = c + dc[i];
            if (newr < 1 || n < newr || newc < 1 || m < newc)
                continue;
            if (D[newr][newc] > D[r][c] + 1){
                D[newr][newc] = D[r][c] + 1;
                Q.push ({newr, newc});
            }
        }
    }
    while (T--){
        int r, c, x;
        cin >> r >> c >> x;
        if (x <= D[r][c]){
            x = ch[r][c] - '0';
            x %= 2;
            cout << x << endl;
            continue;
        }
        x = x - D[r][c] + ch[r][c] - '0';
        x %= 2;
        cout << x << endl;
            continue;
    }
}