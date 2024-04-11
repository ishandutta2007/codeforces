#include<iostream>
#include<cstdio>
#define int long long
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
int a[400002];
signed main()
{
    int t,n,k,ans,maxn,mpos;
    t=read();
    for(int greg=1;greg<=t;greg++)
    {
        n=read();
        k=read();
        for(int i=1;i<=n;i++)a[i]=read();
        ans=0;
        maxn=0;
        mpos=1;
        for(int i=2;i<=n-1;i++)
        {
            if(a[i]>a[i-1]&&a[i]>a[i+1])ans++;
            if(i>=k-1)
            {
                if(ans>maxn)
                {
                   maxn=ans;
                   mpos=i-k+2;
                } 
                if(a[i-k+3]>a[i-k+2]&&a[i-k+3]>a[i-k+4])ans--;
            }
        }
        for(int i=1;i<=n;i++)a[i]=0;
        printf("%lld %lld\n",maxn+1,mpos);
    }    
    //system("pause>nul");
    return 0;
}