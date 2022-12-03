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
const int modo=1000000007;
int val[65][65];
int newval[65][65];
int power(int x,int y)
{
    if (y==0)
    {
        return 1;
    }
    int t=power(x,y/2);
    t=(long long)t*t%modo;
    if (y%2==1)
    {
        t=(long long)t*x%modo;
    }
    return t;
}
int antipower[65];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    long long n;
    cin>>n;
    int k;
    cin>>k;
    int i;
    for (i=0;i<=63;i++)
    {
        val[i][i]=1;
        antipower[i]=power(i,modo-2);
    }
    int l;
    for (l=0;l<k;l++)
    {
        memset(newval,0,sizeof(newval));
        for (i=0;i<=60;i++)
        {
            int j;
            for (j=i;j>=0;j--)
            {
                newval[i][j]=(newval[i][j+1]+(long long)val[i][j]*antipower[j+1])%modo;
            }
        }
        memcpy(val,newval,sizeof(val));
    }
    int ans=1;
    for (i=2;(long long)i*i<=n;i++)
    {
        int cnt=0;
        for (;n%i==0;)
        {
            n/=i;
            cnt++;
        }
        long long p=1;
        int j;
        int sum=0;
        for (j=0;j<=cnt;j++)
        {
            sum=(sum+(long long)p%modo*newval[cnt][j])%modo;
            p=p*i;
        }
        ans=(long long)ans*sum%modo;
    }
    if (n!=1)
    {
        int sum=((long long)newval[1][0]+newval[1][1]*(n%modo))%modo;
        ans=(long long)ans*sum%modo;
    }
    printf("%d\n",ans);
    return 0;
}