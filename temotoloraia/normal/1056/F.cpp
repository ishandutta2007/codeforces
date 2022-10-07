#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define temo

using namespace std;

const int N = 1007;

int Tc;
int n;
double C, T;
double a[N];
int p[N];
double pp[N], pui;
double dp[105][1005][105];
pair < double, int > P[105];

int main()
{
    cin>>Tc;
    pp[0] = 1;
    pui = 10;
    pui /= 9;
    for (int i = 1; i <= 100; i++)
        pp[i] = pp[i - 1] * pui;
    while (Tc--){
        cin>>n>>C>>T;
        for (int i = 1; i <= n; i++){
            cin>>a[i]>>p[i];
            P[i].F = -a[i];
            P[i].S = -p[i];
        }
        sort (P + 1, P + n + 1);
        for (int i = 1; i <= n; i++){
            a[i] = -P[i].F;
            p[i] = -P[i].S;
        }
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= n * 10; j++)
                for (int k = 0; k <= n; k++)
                dp[i][j][k] = -1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i * 10; j++)
                for (int k = 1; k <= i; k++){
                dp[i][j][k] = dp[i - 1][j][k];
                if (j < p[i])
                    continue;
                if (dp[i - 1][j - p[i]][k - 1] == -1)
                    continue;
                if (dp[i][j][k] == -1 || dp[i][j][k] > dp[i - 1][j - p[i]][k - 1] + pp[k] * a[i])
                    dp[i][j][k] = dp[i - 1][j - p[i]][k - 1] + pp[k] * a[i];
            }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i * 10; j++)
                for (int k = 1; k <= i; k++)
                {
                if (dp[i][j][k] == -1)
                    continue;
                double A = dp[i][j][k];
                double t = 0, tt = 1;
                if (A * C > 1){
                    tt = sqrt(A * C);
                    t = (tt - 1) / C;
                }
                double tim = 10 * k + A / tt + t;
                if (tim <= T)
                    ans = max (ans, j);
            }
        cout<<ans<<endl;
    }
    return 0;
}