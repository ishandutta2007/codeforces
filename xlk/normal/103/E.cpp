#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int n,s,t,c,x;
int h[620],v[620],tot=1;
long long z;
struct E
{
	int x,y;
	ll z;
}a[200020];
void add(int x,int y,ll z)
{
	tot++;
	a[tot].x=h[x];
	a[tot].y=y;
	a[tot].z=z;
	h[x]=tot;
	tot++;
	a[tot].x=h[y];
	a[tot].y=x;
	a[tot].z=0;
	h[y]=tot;
}
int bfs()
{
	memset(v,0,sizeof v);
	v[s]=1;
	queue<int>q;
	q.push(s);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=a[i].x)
			if(a[i].z&&!v[a[i].y])
			{
				v[a[i].y]=v[u]+1;
				q.push(a[i].y);
				if(a[i].y==t)
					return 1;
			}
	}
	return 0;
}
ll dfs(int x,ll y)
{
	if(x==t)
		return y;
	ll u=0;
	for(int i=h[x];i;i=a[i].x)
		if(u<y&&a[i].z&&v[a[i].y]==v[x]+1)
		{
			ll k=dfs(a[i].y,min(a[i].z,y-u));
			if(!k)
				v[a[i].y]=0;
			a[i].z-=k;
			a[i^1].z+=k;
			u+=k;
		}
	return u;
}
int main()
{
	scanf("%d",&n);
	s=0,t=2*n+1;
	for(int i=1;i<=n;i++)
		for(scanf("%d",&c);c--;)
			scanf("%d",&x),add(i,n+x,(ll)1e18);
	for(int i=1;i<=n;i++)
		scanf("%d",&x),add(s,i,(ll)1e9-x),z-=(ll)1e9-x;
	for(int i=1;i<=n;i++)
		add(n+i,t,(ll)1e9);
	while(bfs())
		while(ll k=dfs(s,(ll)1e18))
			z+=k;
	cout<<z;
	return 0;
}