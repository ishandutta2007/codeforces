#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int x[35];
int dp[1<<24];
const int modo=1000000007;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    int i;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    int k;
    scanf("%d",&k);
    int x1,x2;
    if (k>0) scanf("%d",&x1); else x1=-1;
    if (k>1) scanf("%d",&x2); else x2=-1;
    int temp=1<<n;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for (register int i=1;i<temp;i++)
    {
        register int sum=0;
        register int j;
        for (j=0;j<n;j++)
        {
            if ((1<<j)&i)
            {
                dp[i]=(dp[i]+dp[i^(1<<j)])%modo;
                sum+=x[j];
                if (sum>modo) sum=modo;
            }
        }
        if ((sum==x1)||(sum==x2)) dp[i]=0;
    }
    printf("%d\n",dp[(1<<n)-1]);
    return 0;
}