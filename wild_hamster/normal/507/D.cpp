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
string s;
ll rez,h,q,n,i,j,k1,k2,k3,d,x,k,y,xx,yy,m,l,r,c,t,sum,dp[1005][105],wasted[1005];
ll pre[10000],pre10[10000];
int main()
{
    cin >> n >> k >> m;
    if (n == 1)
    {
          cout << (9/k)%m << endl;
          return 0;
    } 
    for (i = 0; i < 10; i++)
        dp[0][i%k]++;
    wasted[0] = 1;
    x = 1%k;
    pre[0] = 0;
    pre[1] = 9%m;
    for (i = 2; i < 2000; i++)
        pre[i] = (pre[i-1]*10)%m;
    pre10[0] = 1;
    for (i = 1; i < 2000; i++)
        pre10[i] = (pre10[i-1]*10)%k;
    for (i = 0; i < n-1; i++)
    {
        x = (x*10)%k;
        for (j = 1; j < k; j++)
        if (i < n-2)
            for (l = 0; l < 10; l++)
                dp[i+1][(j+l*x)%k] = (dp[i+1][(j+l*x)%k] + dp[i][j])%m;
        else
            for (l = 1; l < 10; l++)
                dp[i+1][(j+l*x)%k] = (dp[i+1][(j+l*x)%k] + dp[i][j])%m;
                
        if (i < n-2)
            for (l = 0; l < 10; l++)
                dp[i+1][(j+l*x)%k] = (dp[i+1][(j+l*x)%k] + 1)%m;
        else
            for (l = 1; l < 10; l++)
                dp[i+1][(j+l*x)%k] = (dp[i+1][(j+l*x)%k] + 1)%m;
    }
    for (i = 0; i < n; i++)
    {
        //cout << dp[i][0] << " " << pre[n-i-1] << endl;
        rez = (rez + pre[n-i-1]*(dp[i][0]-1)+m)%m;
    }
    cout << (rez+dp[n-1][0])%m << endl;
    return 0;
}