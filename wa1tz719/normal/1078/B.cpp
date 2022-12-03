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
int a[105];
int dp1[10005][105];
int dp2[10005][105];
int n;
int modo1,modo2;
void get_dp()
{
    dp1[0][0]=1;
    dp2[0][0]=1;
    int i;
    for (i=0;i<n;i++)
    {
        int j;
        int t=a[i];
        for (j=10000;j>=t;j--)
        {
            int k;
            for (k=1;k<=n;k++)
            {
                dp1[j][k]+=dp1[j-t][k-1];
                if (dp1[j][k]>=modo1)
                {
                    dp1[j][k]-=modo1;
                }
                dp2[j][k]+=dp2[j-t][k-1];
                if (dp2[j][k]>=modo2)
                {
                    dp2[j][k]-=modo2;
                }
            }
        }
    }
}
bool isprime(int x)
{
    int i;
    for (i=2;i*i<=x;i++)
    {
        if (x%i==0)
        {
            return false;
        }
    }
    return true;
}
int get_random_modo()
{
    for (;;)
    {
        int p=(((rand()<<15)^rand())&0x07ffffff)+0x08000000;
        if (isprime(p))
        {
            return p;
        }
    }
}
int power(int x,int y,int modo)
{
    if (y==0)
    {
        return 1;
    }
    int t=power(x,y/2,modo);
    t=(long long)t*t%modo;
    if (y%2==1)
    {
        t=(long long)t*x%modo;
    }
    return t;
}
int c(int n,int m,int modo)
{
    int i;
    int p=1;
    for (i=1;i<=n;i++)
    {
        p=(long long)p*i%modo;
    }
    for (i=1;i<=m;i++)
    {
        p=(long long)p*power(i,modo-2,modo)%modo;
    }
    for (i=1;i<=n-m;i++)
    {
        p=(long long)p*power(i,modo-2,modo)%modo;
    }
    return p;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    srand(time(0));
    modo1=get_random_modo();
    modo2=get_random_modo();
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for (i=1;i<n;i++)
    {
        if (a[i]!=a[i-1]) break;
    }
    for (i++;i<n;i++)
    {
        if (a[i]!=a[i-1]) break;
    }
    if (i>=n)
    {
        printf("%d\n",n);
        return 0;
    }
    get_dp();
    int cnt=1;
    int ans=0;
    for (i=1;i<=n;i++)
    {
        if ((i!=n)&&(a[i]==a[i-1]))
        {
            cnt++;
        }
        else
        {
            int j;
            for (j=1;j<=cnt;j++)
            {
                if ((dp1[j*a[i-1]][j]==c(cnt,j,modo1))&&(dp2[j*a[i-1]][j]==c(cnt,j,modo2)))
                {
                    ans=max(ans,j);
                }
            }
            cnt=1;
        }
    }
    printf("%d\n",ans);
    return 0;
}