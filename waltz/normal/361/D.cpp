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
int dp[2005];
int a[2005];
int n,k;
bool check(unsigned int x)
{
    if (n==k) return true;
    int i;
    dp[0]=0;
    for (i=1;i<n;i++)
    {
        dp[i]=i;
        int j;
        for (j=0;j<i;j++)
        {
            int t=(a[j]-a[i]);
            if (t<0) t=-t;
            if (t<=x*(long long)(i-j))
            {
                dp[i]=min(dp[i],dp[j]+(i-j-1));
            }
        }
        if (dp[i]+(n-i-1)<=k) return true;
    }
    return false;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%d",&n,&k);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    unsigned int l=0,r=2000000005;
    for (;(l<=r)&&(r<=2000000005);)
    {
        unsigned int mid=(l+r)/2;
        if (check(mid)) r=mid-1; else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}