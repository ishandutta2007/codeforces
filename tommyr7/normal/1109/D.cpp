#include <bits/stdc++.h>
#define modp 1000000007
#define Maxn 2000007
using namespace std;
int n,m,a,b;
int pre[Maxn],inv[Maxn];
int power(int a,int b)
{
    int res=1,now=a,left=b;
    while (left>0)
    {
        if (left%2==1) res=(1LL*res*now)%modp;
        left/=2;
        now=(1LL*now*now)%modp;
    }
    return res;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    pre[0]=1;
    for (int i=1;i<=2000000;i++)
        pre[i]=(1LL*pre[i-1]*i)%modp;
    inv[2000000]=power(pre[2000000],modp-2);
    for (int i=2000000;i;i--)
        inv[i-1]=(1LL*inv[i]*i)%modp;
    int ans=0;
    for (int i=1;i<n&&i<=m;i++)
    {
        int del=power(m,n-i-1);
        del=(1LL*del*pre[m-1])%modp;
        del=(1LL*del*inv[i-1])%modp;
        del=(1LL*del*inv[m-i])%modp;
        del=(1LL*del*pre[n-2])%modp;
        del=(1LL*del*inv[n-i-1])%modp;
        if (i<n-1)
        {
            del=(1LL*del*(i+1))%modp;
            del=(1LL*del*power(n,n-i-2))%modp;
        }
        ans=(ans+del)%modp;
    }
    printf("%d\n",ans);
    return 0;
}