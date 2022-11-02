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
long long dp[55];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int i;
    dp[n+1]=1;
    for (i=n;i>=1;i--)
    {
        dp[i]=dp[i+1]+dp[i+2];
    }
    dp[n+1]=1ll<<62;
    long long k;
    cin>>k;
    k--;
    for (i=1;i<=n;)
    {
        int j;
        for (j=i;j<=i+1;j++)
        {
            if (k>=dp[j+1])
            {
                k-=dp[j+1];
            }
            else
            {
                break;
            }
        }
        int t=j;
        for (j=i+1;j<=t;j++)
        {
            printf("%d ",j);
        }
        printf("%d ",i);
        i=t+1;
    }
    printf("\n");
    return 0;
}