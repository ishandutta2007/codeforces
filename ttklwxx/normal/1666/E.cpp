#include<iostream>
#include<cstdio>
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
int a[200005],n;
bool check(int mid)
{
	int las=0;
	for(int i=1;i<=n;i++)
	{
		las=max(las+mid,a[i]);
		if(las>a[i+1])return false;
	}
	return true;
}
int tmin,tmax;
int ans[200005];
bool check2(int mid)
{
	int lasl=0,lasr=0;
	for(int i=1;i<=n;i++)
	{
		lasl=lasl+tmin;
		lasr=lasr+mid;
		if(lasr<a[i]||lasl>a[i+1])return false;
		lasl=max(lasl,a[i]);
		lasr=min(lasr,a[i+1]); 
		ans[i]=lasr;
	}
//printf("%dorz%d %d\n",mid,lasl,lasr);
	if(lasr==a[n+1])return true;
	return false;
}
int main()
{
	int cd;
	cd=read();
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	a[n+1]=cd;
	int l=0,r=cd,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	tmin=r;
	l=tmin;
	r=cd;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check2(mid))r=mid-1;
		else l=mid+1;
	}
	tmax=l;
	check2(tmax);
	//for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	//printf("\n");
	//rintf("%d %d\n",tmin,tmax);
	ans[n]=cd;
	for(int i=n-1;i>=0;i--)
	{
		ans[i]=min(ans[i],ans[i+1]-tmin);
	}
	for(int i=1;i<=n;i++)printf("%d %d\n",ans[i-1],ans[i]);
	return 0;
}