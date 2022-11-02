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
int power(int x,long long y)
{
    if (y==0) return 1;
    int t=power(x,y/2);
    t=(long long)t*t%modo;
    if (y%2==1)
    {
        t=(long long)t*x%modo;
    }
    return t;
}
long long a[25];
int anti_fact=1;
int c(long long x,int y)
{
    long long i;
    int p=anti_fact;
    for (i=x-y+1;i<=x;i++)
    {
        p=p*(i%modo)%modo;
    }
    return p;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    long long s;
    cin>>s;
    int i;
    for (i=1;i<n;i++)
    {
        anti_fact=(long long)anti_fact*power(i,modo-2)%modo;
    }
    for (i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]++;
    }
    int ans=0;
    for (i=0;i<(1<<n);i++)
    {
        long long t=s;
        int j;
        int count=0;
        for (j=0;j<n;j++)
        {
            if ((1<<j)&i)
            {
                t-=a[j];
                count++;
            }
        }
        if (t<0) continue;
        int flag;
        if (count&1)
        {
            flag=-1;
        }
        else
        {
            flag=1;
        }
        ans+=c(t+n-1,n-1)*flag;
        ans%=modo;
    }
    printf("%d\n",(ans+modo)%modo);
    return 0;
}