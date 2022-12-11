#include <bits/stdc++.h>
#define modp 998244353
using namespace std;
long long L,R;
int k;
int f[27][2][1027],g[27][2][1027],s[27],bit[1027];
long long num[27];
void pre()
{
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    memset(s,0,sizeof(s));
    memset(bit,0,sizeof(bit));
    bit[1]=1;
    for (int i=2;i<1024;i++)
        bit[i]=bit[i/2]+(i%2==1);
    s[0]=1;
    for (int i=1;i<=20;i++)
        s[i]=(10LL*s[i-1])%modp;
    g[0][0][0]=1;
    g[0][1][0]=1;
    for (int i=1;i<=20;i++)
        for (int j=0;j<=9;j++)
        {
            for (int k=0;k<1024;k++)
            {
                g[i][1][k|(1<<j)]=(g[i][1][k|(1<<j)]+g[i-1][1][k])%modp;
                if (j==0) g[i][0][k]=(g[i][0][k]+g[i-1][0][k])%modp; else g[i][0][k|(1<<j)]=(g[i][0][k|(1<<j)]+g[i-1][1][k])%modp;
                f[i][1][k|(1<<j)]=(f[i][1][k|(1<<j)]+f[i-1][1][k])%modp;
                f[i][1][k|(1<<j)]=(f[i][1][k|(1<<j)]+(1LL*j*(1LL*s[i-1]*g[i-1][1][k])%modp)%modp)%modp;
                if (j==0) f[i][0][k]=(f[i][0][k]+f[i-1][0][k])%modp; else
                {
                    f[i][0][k|(1<<j)]=(f[i][0][k|(1<<j)]+f[i-1][1][k])%modp;
                    f[i][0][k|(1<<j)]=(f[i][0][k|(1<<j)]+(1LL*j*(1LL*s[i-1]*g[i-1][1][k])%modp)%modp)%modp;
                }
            }
        }
}
int calc(int now,long long val,int pos)
{
    int res=0;
    if (now==0||now==1)
    {
        for (int i=0;i<1024;i++)
            if (bit[i]<=k) res=(res+f[pos][0][i])%modp;
    } else
    {
        for (int i=0;i<1024;i++)
            if (bit[i|now]<=k)
            {
                res=(res+f[pos][1][i])%modp;
                res=(res+(1LL*(val%modp)*g[pos][1][i])%modp)%modp;
            }
    }
    return (res+modp)%modp;
}
int solve(long long x,int k)
{
    int ans=0,pos=0;
    memset(num,0,sizeof(num));
    long long tmp=x;
    while (tmp>0)
    {
        num[++pos]=tmp%10;
        tmp/=10;
    }
    int now=0;
    long long val=0LL;
    for (int i=1;i<20-i;i++)
        swap(num[i],num[20-i]);
    for (int i=1;i<=19;i++)
    {
        for (int j=0;j<num[i];j++)
            ans=(ans+calc(now|(1<<j),val+1LL*j*s[19-i],19-i))%modp;
        val+=1LL*num[i]*s[19-i];
        if (val!=0LL) now|=(1<<num[i]);
    }
    return ans;
}
int main()
{
    pre();
    scanf("%lld%lld%d",&L,&R,&k);
    printf("%d\n",(solve(R+1,k)+modp-solve(L,k))%modp);
    return 0;
}