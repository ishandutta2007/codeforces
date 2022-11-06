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

long long st10[20];
long long dp[40][20];
char prv[40][20];   
string a, ans;
int i, j, n;

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    st10[0]=1;
    for(i=1; i<18; i++)
        st10[i]=st10[i-1]*10;
    cin >> n >> a;
    for(i=0; i<2*n; i++)
        a[i]-='0';
    dp[1][1]=a[0]*st10[n-1];
    for(i=2; i<=2*n; i++)
        for(j=1; j<=min(i, n); j++)
        {
            if (i-j>n) 
                continue;
            if (j==1)
            {
                dp[i][j]=dp[i-1][j]+a[i-1]*st10[n-(i-j)];
                prv[i][j]=0;
            }
            else
            {
                if (i>j && dp[i-1][j]+a[i-1]*st10[n-(i-j)]>dp[i-1][j-1]+a[i-1]*st10[n-j])
                {
                    dp[i][j]=dp[i-1][j]+a[i-1]*st10[n-(i-j)];
                    prv[i][j]=0;
                }
                else
                {
                    dp[i][j]=dp[i-1][j-1]+a[i-1]*st10[n-j];
                    prv[i][j]=1;
                }
            }
        }
    dp[2*n][n]=dp[2*n][n];
    for(i=2*n, j=n; i>1; i--)
    {
        if (prv[i][j])
            ans.push_back('H');
        else ans.push_back('M');
        j-=prv[i][j];
    }
    ans.push_back('H');
    reverse(ans.begin(), ans.end());
    cout << ans;
}