#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,x[N],y[N],a[N],b[N],c[N],d[N],ans[N];
void add(int x,int v)
{
	for(int i=x;i<=n;i+=i&(-i))
		c[i]+=v;
}
int sum(int x)
{
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v+=c[i];
	return v;
}
void init()
{
	for(int i=0;i<=n;i++)
		c[i]=0;
	for(int i=1;i<=n;i++)
		add(i,1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		x[i]++;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&y[i]);
		y[i]++;
	}
	init();
	for(int i=1;i<=n;i++)
	{
		a[i]=sum(x[i]-1);
		add(x[i],-1);
	}
	init();
	for(int i=1;i<=n;i++)
	{
		b[i]=sum(y[i]-1);
		add(y[i],-1);
	}
	for(int i=n;i>=1;i--)
	{
		int mx=n-i+1;
		d[i]+=a[i]+b[i];
		d[i-1]+=d[i]/mx;
		d[i]=d[i]%mx;
	}
	init();
	for(int i=1;i<=n;i++)
	{
		int l=0,r=n;
		while(r-l>1)
		{
			int m=l+r>>1;
			if(sum(m)<d[i]+1)
				l=m;
			else
				r=m;
		}
		ans[i]=l+1;
		add(l+1,-1);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]-1);
	return 0;
}