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

const int N = 205;

vector < char > V;

vector < int > a, b;

int n, m, k;
int num;

char ch[N][N];
char ans[N][N];
int mas[205];

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    for (char x = '0'; x <= '9'; x++)
        V.pb (x);
    for (char x = 'A'; x <= 'Z'; x++)
        V.pb (x);
    for (char x = 'a'; x <= 'z'; x++)
        V.pb (x);
    int T;
    cin >> T;
    while (T--){
        scanf ("%d %d %d", &n, &m, &k);
        num = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++){
                cin >> ch[i][j];
                if (ch[i][j] == 'R')
                    num++;
            }
        a.clear();
        b.clear();
        for (int i = 1; i <= n; i++){
            if (i % 2 == 1){
                for (int j = 1; j <= m; j++){
                    a.pb (i);
                    b.pb (j);
                }
            }
            else {
                for (int j = m; j >= 1; j--){
                    a.pb (i);
                    b.pb (j);
                }
            }
        }
        int L = n * m;
        for (int i = 0; i < k; i++)
            mas[i] = num / k;
        num %= k;
        for (int i = 0; i < num; i++)
            mas[i]++;
        int last = 0;
        for (int I = 0; I < k; I++){
            int nn = mas[I];
            while (last < L){
                if (ch[a[last]][b[last]] == 'R')
                    nn--;
                if (nn < 0)
                    break;
                ans[a[last]][b[last]] = V[I];
                last++;
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++)
                cout << ans[i][j];
            cout << endl;
        }
    }
    return 0;
}