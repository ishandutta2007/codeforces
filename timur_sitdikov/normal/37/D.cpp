#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back

const int maxn=1005;
long long c[maxn][maxn], dp[105][maxn];
long long x[105], y[105];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n, i, j, k, mod=1000000007, koef, sum, ans;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> x[i];
    for(i=0; i<n; i++)
        cin >> y[i];
    c[0][0]=1;
    for(i=1; i<maxn; i++)
    {
        c[i][0]=1;
        for(j=1; j<=i; j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    /*for(i=0; i<=x[0]; i++)
        dp[0][i]=c[x[0]][i];*/
    dp[0][0]=1;
    for(i=0; i<n; i++)
        for(j=0; j<maxn; j++)
        {
            if (!dp[i][j])
                continue;
            for(k=max(0ll, x[i]+j-y[i]); k<=j+x[i]; k++)
            {
                dp[i+1][k]+=dp[i][j]*c[x[i]+j][k];
                dp[i+1][k]%=mod;
            }
        }
    koef=1;
    sum=0;
    for(i=0; i<n; i++)
        sum+=x[i];
    for(i=0; i<n; i++)
    {
        koef=(koef*c[sum][x[i]])%mod;
        sum-=x[i];
    }
    ans=0;
    for(i=0; i<=y[n-1]-x[n-1]; i++)
        ans=(ans+dp[n-1][i])%mod;
    ans=(ans*koef)%mod;
    cout << ans;
}