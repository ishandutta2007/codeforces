#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 100003
#define MOD2 (33LL+(ll)1e+17)
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 118228
typedef int ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag,timer,start,finita,ans;
ll dp[33][33][55];
string s;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for (i = 1; i <= 30; i++)
        for (j = 1; j <= 30; j++)
        {
            for (k = 0; k <= 50; k++)
                dp[i][j][k] = INF;

            if (i*j <= 50)
               dp[i][j][i*j] = 0;
            dp[i][j][0] = 0;
        }
    dp[1][1][0] = dp[1][1][1] = 0;
    for (i = 1; i <= 30; i++)
        for (j = 1; j <= 30; j++)
            if (i + j > 2)
            {
                for (k = 0; k <= 50; k++)
                {
                    for (n = 1; n <= i-1; n++)
                        for (k1 = 0; k1 <= k; k1++)
                            dp[i][j][k] = min(dp[i][j][k], dp[n][j][k1] + dp[i-n][j][k-k1] + j*j);
                    for (n = 1; n <= j-1; n++)
                        for (k1 = 0; k1 <= k; k1++)
                            dp[i][j][k] = min(dp[i][j][k], dp[i][n][k1] + dp[i][j-n][k-k1] + i*i);

                }
            }
    ll tests;
    cin >> tests;
    for (int ii = 0; ii < tests; ii++)
    {
        cin >> n >> m >> k;
        cout << dp[n][m][k] << endl;
    }
    return 0;
}