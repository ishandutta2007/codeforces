#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
int q[1000100];
struct In{int l,r;}p,v,a,b;
int gao(In x,In y)
{
    In ret;
    ret.l=max(x.l,y.l);
    ret.r=min(x.r,y.r);
    return max(0,ret.r-ret.l+1);
}
int i,j,k,K;
int main()
{
    while(~scanf("%d%d%d%d%d",&p.l,&p.r,&v.l,&v.r,&K))
    {
        int ct=0;
        q[ct++]=min(p.l,v.l)-1;
        for(i=0;i<10;i++)
        {
            for(j=0;j<(1<<i);j++)
            {
                int te=0;
                for(k=0;k<i;k++)
                {
                    te*=10;
                    if(j&(1<<k))te+=4;
                    else te+=7;
                }
                if(te>=min(p.l,v.l)&&te<=max(v.r,p.r))
                q[ct++]=te;
            }
        }
        if(ct<=K){puts("0");continue;}
        q[ct++]=max(p.r,v.r)+1;
        sort(q,q+ct);
    //  for(i=0;i<ct;i++)printf("%d ",q[i]);puts("");
        LL ans=0;
        for(i=0;i+K+1<ct;i++)
        {
            a.l=q[i];
            if(i!=0)a.l++;
            a.r=q[i+1];
            b.l=q[i+K];
            b.r=q[i+K+1];
            if(i+K+1!=ct-1)b.r--;
        //  printf("%d %d %d %d %d\n",i,a.l,a.r,b.l,b.r);
            ans+=(LL)gao(p,a)*gao(v,b);
            ans+=(LL)gao(p,b)*gao(v,a);
            if(K==1&&a.r>=p.l&&a.r<=p.r&&a.r>=v.l&&a.r<=v.r)ans-=1;     
        }
        printf("%.11f\n",(double)ans/(double)(v.r-v.l+1)/(double)(p.r-p.l+1));
    }
}