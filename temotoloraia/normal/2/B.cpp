#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LL long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MAXN = 1000;
int n;
int a[MAXN + 5][MAXN + 5], b[MAXN + 5][MAXN + 5];
int dp2[MAXN + 5][MAXN + 5];
int fr2x[MAXN + 5][MAXN + 5], fr2y[MAXN + 5][MAXN + 5];
int dp5[MAXN + 5][MAXN + 5];
int fr5x[MAXN + 5][MAXN + 5], fr5y[MAXN + 5][MAXN + 5];
char ch[MAXN * 2 + 5];
int i, j;
int B[300], F[300];
int nn, np;
int M = 1e9;
int r, c;
int main()
{
    B[0] = 1;
    for (nn = 1; B[nn - 1] < M/2; nn++)
        B[nn] = B[nn - 1] * 2;
    F[0] = 1;
    for (np = 1; F[np - 1] < M/5; np++)
        F[np] = F[np - 1] * 5;
    cin>>n;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j){
            int x;
            scanf("%d", &x);
            if (x == 0)
                r = i, c = j;
            for (int I = 5; I >= 0; I--){
                int p = a[i][j] + (1<<I);
                if (p >= nn)
                    continue;
                if (x % B[p] == 0)
                    a[i][j] = p;
            }
            for (int I = 5; I >= 0; I--){
                int p = b[i][j] + (1<<I);
                if (p >= np)
                    continue;
                if (x % F[p] == 0)
                    b[i][j] = p;
            }
        }
    for (i = 0; i <= n; ++i){
        dp2[i][0] = 1e9;
        dp2[0][i] = 1e9;
        dp5[i][0] = 1e9;
        dp5[0][i] = 1e9;
    }
    dp2[0][1] = 0;
    dp5[0][1] = 0;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j){
            if (dp2[i - 1][j] < dp2[i][j - 1]){
                dp2[i][j] = dp2[i - 1][j];
                fr2x[i][j] = i - 1;
                fr2y[i][j] = j;
            }
            else {
                dp2[i][j] = dp2[i][j - 1];
                fr2x[i][j] = i;
                fr2y[i][j] = j - 1;
            }
            dp2[i][j] += a[i][j];
        }
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j){
            if (dp5[i - 1][j] < dp5[i][j - 1]){
                dp5[i][j] = dp5[i - 1][j];
                fr5x[i][j] = i - 1;
                fr5y[i][j] = j;
            }
            else {
                dp5[i][j] = dp5[i][j - 1];
                fr5x[i][j] = i;
                fr5y[i][j] = j - 1;
            }
            dp5[i][j] += b[i][j];
        }
    if (r && dp2[n][n] && dp5[n][n]){
        cout<<"1\n";
        for (int i = 0; i < r - 1; i++)
            cout<<"D";
        for (int i = 0; i < n - 1; i++)
            cout<<"R";
        for (int i = r; i < n; i++)
            cout<<"D";
        return 0;
    }
    cout<<min (dp2[n][n], dp5[n][n])<<endl;
    if (dp2[n][n] <= dp5[n][n]){
        int x = n, y = n;
        while (x + y > 2){
            if (x == fr2x[x][y])
                ch[x + y] = 'R';
            else
                ch[x + y] = 'D';
            int p = fr2x[x][y];
            int q = fr2y[x][y];
            x = p;
            y = q;
        }
    }
    else {
        int x = n, y = n;
        while (x + y > 2){
            if (x == fr5x[x][y])
                ch[x + y] = 'R';
            else
                ch[x + y] = 'D';
            int p = fr5x[x][y];
            int q = fr5y[x][y];
            x = p;
            y = q;
        }
    }
    for (int i = 3; i <= n * 2; i++)
        cout<<ch[i];
    return 0;
}