#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
typedef long long ll;
using namespace std;
ll n,i,j,d,m,x,y,p,k,max1,a[5000],b[5000],rez,rows,cols;
double dp[2200][2200];
string s;

int main()
{
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        if (a[x] == 0) rows++;
        if (b[y] == 0) cols++;
        a[x] = 1;
        b[y] = 1;
    }
    
    for(i = 1; i <= n; i++) dp[i][0] = dp[i-1][0] + (double)n / i;
    for(j = 1; j <= n; j++) dp[0][j] = dp[0][j-1] + (double)n / j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            double x = 0;
            
            x = (dp[i-1][j]*(double)(i*(n-j))
            + dp[i][j-1]*(double)((n-i)*j)
            + dp[i-1][j-1]*(double)(i*j))/(double)(n*n);          
            dp[i][j] = x+1.;  
            dp[i][j]/=(1.-(double)((n-i)*(n-j))/(n*n));
        }
   // if (m == 616) cout << cols << " " << rows << endl;
    printf("%.10f\n",dp[n-rows][n-cols]);
    return 0;
}