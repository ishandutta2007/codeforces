#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
const int P=1000000007;
const int V=1000100;
int dp[2],n;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        dp[0]=dp[1]=0;
        for(int i=0;i<n;i++)
        {
            int ct=dp[i%2]+1;
            dp[(i+1)%2]+=ct;
            dp[(i+1)%2]%=P;
        }
        printf("%d\n",(dp[0]+dp[1])%P);
    }
}