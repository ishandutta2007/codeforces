#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=5100;
const int P=1000000007;
char s[V],t[V];
int dp[V][V],n,m,i,j,sm[V];
int main()
{
    while(~scanf("%s%s",s,t))
    {
        memset(dp,0,sizeof(dp));
        n=strlen(s);
        m=strlen(t);
        LL ret=0;
        memset(sm,0,sizeof(sm));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(s[i]==t[j])
                {
                    if(j==0)dp[i][j]=1;
                    else dp[i][j]=(sm[j-1]+1)%P;
                }
                else dp[i][j]=0;
                ret=(ret+dp[i][j])%P;
            //    printf("%d %d %d\n",i,j,dp[i][j]);
            }
            sm[0]=dp[i][0];
            for(j=1;j<m;j++)
            sm[j]=(sm[j-1]+dp[i][j])%P;
        }
        cout<<ret<<endl;
    }
}