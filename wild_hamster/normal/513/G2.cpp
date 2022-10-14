#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll l,r,i,j,n,k,d,m,p[105];
double dp[35][35],tmp[35][35],rez;
int main()
{
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> p[i];
    for (i = 1; i <= n; i++)
        for (j = i+1; j <= n; j++)
        if (p[i] > p[j])
            dp[i][j] = 1.0;
        else
            dp[j][i] = 1.0;
    
    for (m = 0; m < k; m++)
    {
        for (l = 1; l <= n; l++)
            for (r = l; r <= n; r++)
                for (i = 1; i <= n; i++)
                    for (j = i+1; j <= n; j++)
                    if (i >= l && j <= r)
                    {
                        tmp[i][j] += dp[l+r-i][l+r-j]/(double)((n*(n+1))/2);
                    } else
                    if (i < l && j >= l && j <= r)
                    {
                        tmp[i][j] += dp[i][l+r-j]/(double)((n*(n+1))/2);
                    } else
                    if (j > r && i >= l && i <= r)
                    {
                        tmp[i][j] += dp[l+r-i][j]/(double)((n*(n+1))/2);
                    } else
                    {
                        tmp[i][j] += dp[i][j]/(double)((n*(n+1))/2);
                    }
        for (i = 1; i <= n; i++)
            for (j = i+1; j <= n; j++)
            {
             dp[i][j] = tmp[i][j];
             dp[j][i] = 1.-tmp[i][j];
             tmp[i][j] = tmp[j][i] = 0;
            }
    }
    for (i = 1; i <= n; i++)
        for (j = i+1; j <= n; j++)
            rez += dp[i][j];
    printf("%.10f\n",rez);
    return 0;
}