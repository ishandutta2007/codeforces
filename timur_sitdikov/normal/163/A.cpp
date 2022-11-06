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

int dp[5005][5005];
char s[5005], t[5005];

int main()
{   

    int n, mod=1000000007, sum, ans=0, i, j, ls, lt;
    scanf("%s %s", &s, &t);
    ls=strlen(s);
    lt=strlen(t);
    for(j=0; j<lt; j++)
        if (s[0]==t[j]) dp[0][j]=1;
    for(i=1; i<ls; i++)
    {
        sum=0;
        for(j=0; j<lt; j++)
        {
            if (s[i]==t[j])
            {
                dp[i][j]+=1+sum;
                if (dp[i][j]>=mod) dp[i][j]-=mod;
            }
            sum+=dp[i-1][j];
            if (sum>=mod) sum-=mod;
        }
    }
    for(i=0; i<ls; i++)
        for(j=0; j<lt; j++)
        {
            ans+=dp[i][j];
            if (ans>=mod) ans-=mod;
        }
    printf("%d", ans);

}