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

const int inf=1000000000;
const int maxn=105;
int dp[maxn][maxn][11];
char prv[maxn][maxn][11];
char s[maxn][maxn];
vector<int> ans;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k, i, j, l, maxi, l1;
    cin >> n >> m >> k;
    k++;
    for(i=0; i<n; i++)
        scanf("%s", &s[i]);
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            for(l=0; l<k; l++)
                dp[i][j][l]=-inf;
    for(j=0; j<m; j++)
        dp[n-1][j][(s[n-1][j]-'0')%k]=s[n-1][j]-'0';
    for(i=n-1; i>0; i--)
        for(j=0; j<m; j++)  
            for(l=0; l<k; l++)
            {
                if (dp[i][j][l]<0)
                    continue;
                if (j && dp[i-1][j-1][(l+s[i-1][j-1]-'0')%k]<s[i-1][j-1]-'0'+dp[i][j][l])
                {
                     dp[i-1][j-1][(l+s[i-1][j-1]-'0')%k]=s[i-1][j-1]-'0'+dp[i][j][l];
                     prv[i-1][j-1][(l+s[i-1][j-1]-'0')%k]=1;
                }
                if (j<m-1 && dp[i-1][j+1][(l+s[i-1][j+1]-'0')%k]<s[i-1][j+1]-'0'+dp[i][j][l])
                {
                     dp[i-1][j+1][(l+s[i-1][j+1]-'0')%k]=s[i-1][j+1]-'0'+dp[i][j][l];
                     prv[i-1][j+1][(l+s[i-1][j+1]-'0')%k]=-1;
                }
            }

    maxi=0;
    for(j=1; j<m; j++)
        if (dp[0][j][0]>dp[0][maxi][0])
            maxi=j;
    if (dp[0][maxi][0]<0)
    {
        printf("-1");
        return 0;
    }
    for(l=0, j=maxi, i=0; i<n; i++)
    {
        ans.pb(j);
        l1=(l+10*k-s[i][j]+'0')%k;
        j+=prv[i][j][l];
        l=l1;
    }
    printf("%d\n%d\n", dp[0][maxi][0], j+1);
    for(i=ans.size()-1; i>0; i--)
    {
        if (ans[i]<ans[i-1])
            putchar('R');
        else putchar('L');
    }
}