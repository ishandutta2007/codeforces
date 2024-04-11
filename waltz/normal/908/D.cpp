#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[1005][1005];
const int modo=1000000007;
int power(int x,int y)
{
    if (y==0) return 1;
    int t=power(x,y/2);
    t=(long long)t*t%modo;
    if (y%2==1) t=(long long)t*x%modo;
    return t;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int k,pa,pb;
    scanf("%d%d%d",&k,&pa,&pb);
    int t=power(pa+pb,modo-2);
    int cb=power(pb,modo-2);
    int i;
    dp[0][0]=1;
    int ans=0;
    for (i=0;i<=k;i++)
    {
        int j;
        for (j=0;j<k;j++)
        {
            if (j+i<k)
            {
                if (i!=0) dp[i][j+i]=(dp[i][j+i]+(long long)dp[i][j]*pb%modo*t%modo)%modo;
            }
            else
            {
                ans=(ans+(long long)dp[i][j]*pb%modo*t%modo*(j+i))%modo;
            }
            if (i+1+j>=k)
            {
                if (i!=0)
                {
                    ans=(ans+((long long)dp[i][j]*pa%modo*t%modo*(j+i+1+(long long)pa*cb%modo)))%modo;
                }
                else
                {
                    ans=(ans+((long long)dp[i][j]*(j+i+1+(long long)pa*cb%modo)))%modo;
                }
            }
            else
            {
                if (i!=0)
                {
                    dp[i+1][j]=(dp[i+1][j]+(long long)dp[i][j]*pa%modo*t)%modo;
                }
                else
                {
                    dp[i+1][j]=(dp[i+1][j]+(long long)dp[i][j])%modo;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}