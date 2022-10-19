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
int d[1000001];
signed main()
{
    int n,x,ans=0,nsl=0,qs,nans=0;
    n=read();
    x=read();
    for(int i=1;i<=n;i++)
    {
    	d[i]=read();
    	d[i+n]=d[i];
	}
	qs=1;
	for(int i=1;i<=2*n;i++)
	{
		nsl+=d[i];
		nans+=d[i]*(d[i]+1)/2;
		while(nsl>x)nsl-=d[qs],nans-=d[qs]*(d[qs]+1)/2,qs++;
		if(x-nsl>d[qs-1])continue;
		ans=max(ans,nans+(d[qs-1]*2-x+nsl+1)*(x-nsl)/2);
	}
	printf("%lld\n",ans);
	return 0;
}