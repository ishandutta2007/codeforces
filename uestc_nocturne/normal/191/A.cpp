/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
int dp[30][30],te[30][30],n,ret,i,j,le;
char s[120];
int main()
{
    while(~scanf("%d",&n))
    {
        ret=0;
        for(i=0;i<26;i++)
        for(j=0;j<26;j++)
        {
            dp[i][j]=-1000000000;
        }
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            le=strlen(s);
            for(j=0;j<26;j++)
            {
                te[j][s[le-1]-'a']=dp[j][s[0]-'a']+le;
            }
            for(j=0;j<26;j++)
            dp[j][s[le-1]-'a']=max(dp[j][s[le-1]-'a'],te[j][s[le-1]-'a']);
            dp[s[0]-'a'][s[le-1]-'a']=max(dp[s[0]-'a'][s[le-1]-'a'],le);
        }
        for(i=0;i<26;i++)ret=max(ret,dp[i][i]);
        cout<<ret<<endl;
    }
}