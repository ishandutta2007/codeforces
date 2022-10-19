// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<cmath>
#pragma GCC optimize(2)
using namespace std;
inline int read()
{
    int n=0,f=1,ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n*f;
}
int pos[100001],ks[100001],jo[100001],jd[100001],tf[100001];
int main()
{
    int n,kk,m;
    n=read();
    m=read();
    kk=1.2*sqrt(n);
    for(int i=1;i<=n;i++)tf[i]=read();
    for(int i=1;i<=n;i++)ks[i]=i/kk+1;
    for(int i=n;i>=1;i--)
    {
        if(ks[i+tf[i]]!=ks[i])
        {
            jo[i]=1;
            jd[i]=i;	
        }
        else
        {
            jo[i]=jo[i+tf[i]]+1;
            jd[i]=jd[i+tf[i]];
        }
    }
    int zl,x,y,ans;
    for(int i=1;i<=m;i++)
    {
        zl=read();
        if(zl==1)
        {
            x=read();
            ans=0;
            while(1)
            {
                ans+=jo[x];
                x=jd[x];
                if(x+tf[x]>n)break;
                x+=tf[x];
            }
            printf("%d %d\n",x,ans);
        }
        else
        {
            x=read();
            y=read();
            tf[x]=y;
            for(int i=x;ks[i]==ks[x];i--)
            {
                if(ks[i+tf[i]]!=ks[i])
                {
                    jo[i]=1;
                    jd[i]=i;
                }
                else
                {
                    jo[i]=jo[i+tf[i]]+1;
                    jd[i]=jd[i+tf[i]];
                }
            }
        }
    }
    return 0;
}