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
int findmin(int n)
{
    int l=1,r=100000,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(mid*(3*mid+1)/2<=n)l=mid+1;
        else r=mid-1;
    }
    return r;
}
signed main()
{
    int t,n,k,ans;
    t=read();
    for(int greg=1;greg<=t;greg++)
    {
        n=read();
        ans=0;
        while(n>=2)
        {
            k=findmin(n);
            n-=k*(3*k+1)/2;
            ans++;
        }
        printf("%lld\n",ans);
    }
    //system("pause");
    return 0;
}