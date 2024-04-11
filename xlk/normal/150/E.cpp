#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for (int i=0;i<n;i++)
#define fo(i,n) for (int i=1;i<=n;i++)
#define X first
#define Y second
#define N 100020
typedef pair<int,int>ii;
int n,x,y,w,l,r,M;
int q[N],f[N],sz[N],d[N],dd[N],mx[N];
ii z,c[N],a[N];
vector<ii>e[N];
int fd(int x)
{
	int t=1;
	f[x]=0,q[0]=x;
	fr(i,t)
	{
		for(ii y:e[q[i]])
			if(dd[y.X]>n&&y.X!=f[q[i]])
				f[q[t++]=y.X]=q[i];
		sz[q[i]]=1;
	}
	for(int i=t;i--;)
	{
		if(sz[q[i]]*2>t)
			return q[i];
		sz[f[q[i]]]+=sz[q[i]];
	}
}
void mak(int x,int f,int D)
{
	d[x]=1;
	for(ii y:e[x])
		if(y.X!=f&&dd[y.X]>D)
		{
			mak(y.X,x,D);
			d[x]=max(d[x],d[y.X]+1);
		}
}
bool cmp(ii a,ii b)
{
	return d[a.X]<d[b.X];
}
void mk(int x,int D)
{
	dd[x=fd(x)]=D;mx[x]=1;
	for(ii y:e[x])
		if(dd[y.X]>n)
			mk(y.X,D+1);
	mak(x,-1,D);
	sort(e[x].begin(),e[x].end(),cmp);
	mx[x]=d[x]-1;
}
void dfs(int x,int y,int d,int D,int l)
{
	if(c[d].X<l)
		c[d]=ii(l,x);
	for(ii i:e[x])
		if(i.X!=y&&dd[i.X]>D)
			dfs(i.X,x,d+1,D,l+(i.Y<M?-1:1));
}
bool ck(int x)
{
	a[0]=ii(0,x);
	fo(i,mx[x])
		a[i]=ii(0xc0c0c0c0,0);
	int ct=0,h,t,f;
	for(ii y:e[x])
		if(dd[y.X]>dd[x])
		{
			mak(y.X,x,dd[x]);
			fo(i,d[y.X])
				c[i]=ii(0xc0c0c0c0,0);
			dfs(y.X,x,1,dd[x],y.Y<M?-1:1);
			f=ct;
			h=1,t=0;
			fo(i,d[y.X])
			{
				while(f+i>=l&&f>=0)
				{
					while(h<=t&&a[q[t]].X<a[f].X)
						t--;
					q[++t]=f;
					f--;
				}
				while(h<=t&&q[h]+i>r)
					h++;
				if(h<=t&&a[q[h]].X+c[i].X>=0)
					return z=ii(a[q[h]].Y,c[i].Y),1;
			}
			fo(i,d[y.X])
				a[i]=max(a[i],c[i]);
			ct=d[y.X];
		}
	return 0;
}
int ok()
{
	fr(i,n)
		if(ck(i))
			return 1;
	return 0;
}
int main()
{
	scanf("%d%d%d",&n,&l,&r);
	int L=-1,R=0;
	fr(i,n-1)
	{
		scanf("%d%d%d",&x,&y,&w);
		x--,y--;
		e[x].push_back(ii(y,w));
		e[y].push_back(ii(x,w));
		R=max(R,w+1);
	}
	fr(i,n)
		dd[i]=n+1;
	mk(0,1);
	while(L<R-1)
	{
		M=(L+R)>>1;
		if(ok())
			L=M;
		else
			R=M;
	}
	printf("%d %d\n",z.X+1,z.Y+1);
}