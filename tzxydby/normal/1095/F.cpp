#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long v[N],par[N];
struct edge
{
	int x,y;
	long long w;
	bool operator<(const edge t)const
	{ 
		return w<t.w;
	}
}a[N*2];
int find(int x)
{
	if(par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
int main()
{
	int n,m,p,cnt=0;
	long long mn=LLONG_MAX;
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
		scanf("%I64d",&v[i]);
		if(mn>v[i])
		{
			mn=v[i];
			p=i;
		}
	}
	for(int i=1;i<=m;i++)
		scanf("%d%d%I64d",&a[i].x,&a[i].y,&a[i].w);
	for(int i=1;i<=n;i++)
	{
		if(i==p)
			continue;
		m++;
		a[m].x=p;
		a[m].y=i;
		a[m].w=v[p]+v[i];
	}
	sort(a+1,a+1+m);
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx==fy)
			continue;
		ans+=a[i].w;
		par[fx]=fy;
		cnt++;
		if(cnt==n-1)
		{
			cout<<ans<<endl;
			break;
		}
	}
	return 0;
}