#include <bits/stdc++.h>
using namespace std;
int n,K;
#define Maxn 307
#define modp 1000000007
int c[Maxn][Maxn];
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
    c[0][0]=1;
    for (int i=1;i<=300;i++)
    {
        c[i][0]=1;
        for (int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%modp;
    }
    scanf("%d%d",&n,&K);
    int ans=0;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
        {
            int tmp=n*(i+j)-i*j;
            int del=(1LL*power(K-1,tmp)*power(K,n*n-tmp))%modp;
            del=(1LL*del*c[n][i])%modp;
            del=(1LL*del*c[n][j])%modp;
            if ((i+j)%2==0) ans=(ans+del)%modp; else ans=(ans+modp-del)%modp;
        }
    printf("%d\n",ans);
    return 0;
}