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
using namespace std;

const long long nmax=105, d=15;
const long long mod=1000000007;
long long dp[nmax][d+5];
long long c[nmax][nmax];
long long a[d];

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    long long n, i, j, k, s;
    long long ans;
    cin >> n;
    for(i=0; i<=n; i++)
        c[i][0]=c[i][i]=1;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    for(i=0; i<10; i++)
        cin >> a[i];
    a[10]=a[0];
    for(i=a[1]; i<=n; i++)
        dp[i][1]=1;
    for(i=0; i<=n; i++)
        for(j=2; j<=10; j++)
        {
            for(k=a[j]; k<=i; k++)
            {
                if (j<10)
                    dp[i][j]=(dp[i][j]+dp[i-k][j-1]*c[i][k])%mod;
                else 
                {
                    if (i && k<i)
                        dp[i][j]=(dp[i][j]+dp[i-k][j-1]*c[i-1][k])%mod;
                }
            }
        }
    ans=0;
    for(i=1; i<=n; i++)
        ans=(ans+dp[i][10])%mod;
    cout << ans;

        

}