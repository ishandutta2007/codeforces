#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct _
{
	int x,y,w;
};
bool operator >(_ a,_ b)
{
	return a.w>b.w;
}
priority_queue<_,vector<_>,greater<_> > q;
const int mx=2e5+5;
int f[mx],s[mx];
struct Q
{
	int W,id;
	ll ans;
}a[mx];
bool cmp(Q x,Q y)
{
	return x.W<y.W;
}
int get(int x)
{
	return f[x]!=x?f[x]=get(f[x]):x;
}
ll sum(int x)
{
	return (ll)x*(x-1)/2;
}
bool cmp1(Q x,Q y)
{
	return x.id<y.id;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		q.push(_{x,y,w});
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i].W);
		a[i].id=i;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i,s[i]=1;
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		while(q.size()&&q.top().w<=a[i].W)
		{
			int tx=get(q.top().x),ty=get(q.top().y);
			if(tx!=ty)
			{
				ans-=sum(s[tx])+sum(s[ty]);
				ans+=sum(s[tx]+s[ty]);
				f[tx]=ty;
				s[ty]+=s[tx];
			}
			q.pop();
		}
		a[i].ans=ans;
	}
	sort(a+1,a+m+1,cmp1);
	for(int i=1;i<=m;i++) printf("%lld ",a[i].ans);
	return 0;
}