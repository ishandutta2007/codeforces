#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
#define MOD 1000000007
char s[233333];
int n,dp[5003][5003],qzh[5003][5003],gg[5003][5003];
void MM(int& x)
{
    while(x<0) x+=MOD;
    while(x>=MOD) x-=MOD;
}
int main()
{
    scanf("%d%s",&n,s+1);
    for(int i=n;i>=1;i--)
    {
        for(int j=n;j>=i;j--)
        {
            if(s[i]!=s[j]) gg[i][j]=i;
            else if(j==n) gg[i][j]=1333333333;
            else gg[i][j]=gg[i+1][j+1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=1;
        for(int j=1;j<=n;j++) qzh[j][i]=1;
    }
    int Ans=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int l=2*i-j-1,r=i-1;
            int ans=0;
            if(s[i]!='0'){
            ans=qzh[r][r]-qzh[max(l,0)][r];
            MM(ans);
            if(l>=1)
            {
                int rp=gg[l][i];
                if(rp<i&&s[rp]<s[i+(rp-l)])
                {
                    ans+=dp[l][r];
                    MM(ans);
                }
            }
            }
            dp[i][j]=ans;
            qzh[i][j]=qzh[i-1][j]+ans;
            MM(qzh[i][j]);
            if(j==n) Ans+=dp[i][j], MM(Ans);
        }
    }
    printf("%d\n",Ans);
}