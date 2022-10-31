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
int a[2005];
int gcd(int x,int y)
{
    if (y==0) return x;
    return gcd(y,x%y);
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    int sum=0;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]==1) sum++;
    }
    if (sum!=0)
    {
        printf("%d\n",n-sum);
        return 0;
    }
    int ans=n+1;
    for (i=0;i<n;i++)
    {
        int j;
        int now=a[i];
        for (j=i+1;j<n;j++)
        {
            now=gcd(now,a[j]);
            if (now==1) break;
        }
        if (j!=n)
        {
            ans=min(ans,j-i);
        }
    }
    if (ans==n+1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",ans+n-1);
    }
    return 0;
}