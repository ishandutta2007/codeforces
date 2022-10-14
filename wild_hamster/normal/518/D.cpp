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
ll x,y,l,r,i,j,n,k,k1,k2,d,m,a[100500],b[100500],q,dr;
double dp[2005][2005];
double p;
int main()
{
    //freopen("thimble.in","r",stdin);
    //freopen("thimble.out","w",stdout);
    cin >> n >> p >> k;
    double q = 1.-p;
    dp[0][0] = 1;
    for (i = 0; i < k; i++)
        for (j = 0; j <= n; j++)
        {
            dp[i+1][j] += q*dp[i][j];
            dp[i+1][min(j+1,n)] += p*dp[i][j];
        }
    double rez = 0;
    for (i = 1; i <= n; i++)
        rez += dp[k][i]*(double)i;
    printf("%.10f\n",rez);
    return 0;
}