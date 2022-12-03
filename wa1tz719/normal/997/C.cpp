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
const int modo=998244353;
int power(int x,int y)
{
    if (y==0) return 1;
    int t=power(x,y/2);
    t=(long long)t*t%modo;
    if (y%2==1) t=(long long)t*x%modo;
    return t;
}
int pow3[100005];
int pow3_head[100005];
int fact[1000005];
int anti_fact[1000005];
int power3(long long x)
{
    x%=(modo-1);
    return (long long)pow3_head[x/100000]*pow3[x%100000]%modo;
}
int c(int n,int x)
{
    return (long long)fact[n]*anti_fact[x]%modo*anti_fact[n-x]%modo;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i;
    pow3[0]=1;
    for (i=1;i<=100000;i++)
    {
        pow3[i]=(long long)pow3[i-1]*3%modo;
    }
    pow3_head[0]=1;
    for (i=1;i<=100000;i++)
    {
        pow3_head[i]=(long long)pow3_head[i-1]*pow3[100000]%modo;
    }
    fact[0]=1;
    for (i=1;i<=1000000;i++)
    {
        fact[i]=(long long)fact[i-1]*i%modo;
    }
    anti_fact[1000000]=power(fact[1000000],modo-2);
    for (i=1000000;i>=1;i--)
    {
        anti_fact[i-1]=(long long)anti_fact[i]*i%modo;
    }
    int n;
    scanf("%d",&n);
    int ans=0;
    int p=-1;
    for (i=1;i<=n;i++)
    {
        p*=-1;
        ans=(ans+p*(long long)c(n,i)*power3(i)%modo*power3((long long)(n-i)*n))%modo;
        ans=(ans+p*(long long)c(n,i)*power3(i)%modo*power3((long long)(n-i)*n))%modo;
        ans=(ans-p*(long long)c(n,i)*3%modo*power3((long long)(n-i)*n))%modo;
    }
    p=-1;
    for (i=1;i<=n;i++)
    {
        p*=-1;
        ans=(ans+p*c(n,i)*(long long)3*power(power3(n-i)-1,n))%modo;
    }
    ans=(ans+modo)%modo;
    printf("%d\n",ans);
    return 0;
}