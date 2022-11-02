#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
bool check(int x)
{
    while(x>0)
    {
        if(x%10!=4&&x%10!=7)return false;
        x/=10;
    }
    return true;
}
LL fac[120];
LL q[1000100],te;
int vis[1200],va[1200];
int i,j,le,ans,N,ml,n,k;
int main()
{
    fac[0]=1;
    for(i=1;;i++)
    {
        fac[i]=fac[i-1]*i;
    //  printf("%d %lld %lld\n",i,fac[i],fac[i-1]);
        if(fac[i]>=1000000000)
        {ml=i;break;}
    }
    while(~scanf("%d%d",&n,&k))
    {
        if(n<=ml&&fac[n]<k)
        {puts("-1");continue;}
        k--;
        int ct=0;
        for(N=1;N<=10;N++)
        {
            for(i=0;i<(1<<N);i++)
            {
                LL te=0;
                for(j=0;j<N;j++)
                {
                    te*=10;
                    if(i&(1<<j))te+=4;
                    else te+=7;
                }
                q[ct++]=te;
            }
        }
        sort(q,q+ct);
        le=min(n,ml);
        ans=0;
        for(i=0;i<ct;i++)
        if(q[i]<=n-le)ans++;
        else break;
        memset(vis,0,sizeof(vis));
        for(i=0;i<le;i++)
        {
            int nu=k/fac[le-i-1];
            k-=fac[le-i-1]*nu;
            j=1;
            while(nu)
            {
                if(!vis[j])nu--;
                j++;
            }
            while(vis[j])j++;
            va[i]=j;vis[j]=1;
        }
    //  for(i=0;i<le;i++)printf("%d ",va[i]);puts("");
        for(i=0;i<le;i++)
        {
            if(check(i+1+n-le)&&check(va[i]+n-le))
            ans++;
        }
        cout<<ans<<endl;
    }
}