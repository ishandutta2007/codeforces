#include<iostream>
#include<cstdio>
#include<algorithm>
#define int unsigned long long
using namespace std;
struct a
{
    int l,k;
}cz[800004];
bool bi(struct a x,struct a y)
{
    return x.l<y.l;
}
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
int ans[200001];
signed main()
{
    int n,l,r,x=0;
    n=read();
    for(int i=1;i<=n;i++)
    {
    	l=read();
    	r=read();
    	cz[2*i-1].l=l;
    	cz[2*i-1].k=1;
    	cz[2*i].l=r+1;
    	cz[2*i].k=-1;
    }
    sort(cz+1,cz+2*n+1,bi);
    for(int i=1;i<=2*n;i++)
    {
    	if(x!=0)ans[x]+=cz[i].l-cz[i-1].l;
    	x+=cz[i].k;
    }
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
    return 0;
}