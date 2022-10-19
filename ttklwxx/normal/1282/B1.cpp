#include<iostream>
#include<cstdio>
#include<algorithm>
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
int a[500001];
signed main()
{
    int t,n,p,k,sth,l,r,mid,fy=0;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	n=read();
    	p=read();
    	k=read();
    	for(int j=1;j<=n;j++)a[j]=read();
    	sort(a+1,a+n+1);
    	l=1;
    	r=n;
    	while(l<=r)
    	{
    		mid=(l+r)>>1;
    		fy=0;
    		for(sth=mid;sth>=0;sth-=k)fy+=a[sth];
    		for(;sth>=1;sth--)fy+=a[sth];
    		if(fy<=p)l=mid+1;
    		else r=mid-1;
		}
		printf("%lld\n",r);
	}
    return 0;
}