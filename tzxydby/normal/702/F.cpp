#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int rt,cnt,lc[N],rc[N],sz[N],r[N],v[N];
int s[N],t[N],t2[N];
void pushup(int u)
{
	sz[u]=sz[lc[u]]+sz[rc[u]]+1;
}
void pushdown(int u)
{
	if(t[u])
	{
		if(lc[u]) t[lc[u]]+=t[u],s[lc[u]]+=t[u];
		if(rc[u]) t[rc[u]]+=t[u],s[rc[u]]+=t[u];
		t[u]=0;
	}
	if(t2[u])
	{
		if(lc[u]) t2[lc[u]]+=t2[u],v[lc[u]]-=t2[u];
		if(rc[u]) t2[rc[u]]+=t2[u],v[rc[u]]-=t2[u];
		t2[u]=0;
	}
}
void print(int u)
{
	if(!u)
		return;
	pushdown(u);
	print(lc[u]);
	print(rc[u]);
}
int merge(int x,int y)
{
	if(!x||!y)
		return x+y;
	pushdown(x),pushdown(y);
	pushup(x),pushup(y);
	if(r[x]<r[y])
	{
		rc[x]=merge(rc[x],y);
		pushup(x);
		return x;
	}
	else
	{
		lc[y]=merge(x,lc[y]);
		pushup(y);
		return y;
	}
}
void split(int u,int k,int &x,int &y)
{
	if(!u)
	{
		x=y=0;
		return;
	}
	pushdown(u);
	if(v[u]<=k)
	{
		x=u;
		split(rc[u],k,rc[u],y);
	}
	else
	{
		y=u;
		split(lc[u],k,x,lc[u]);
	}
	pushup(u);
}
void Split(int u,int k,int &x,int &y)
{
	if(!u)
	{
		x=y=0;
		return;
	}
	pushdown(u);
	if(sz[lc[u]]>=k)
	{
		y=u;
		Split(lc[u],k,x,lc[u]);
	}
	else
	{
		x=u;
		Split(rc[u],k-sz[lc[u]]-1,rc[u],y);
	}
	pushup(u);
}
int node(int val)
{
	cnt++;
	lc[cnt]=rc[cnt]=0;
	v[cnt]=val;
	sz[cnt]=1;
	r[cnt]=rand();
	return cnt;
}
struct node
{
	int c,q;
	bool operator<(const node x)const
	{
		return q==x.q?c<x.c:q>x.q;
	}
}a[N];
int n,m;
queue<int>q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].c,&a[i].q);
	sort(a+1,a+n+1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int k,x,y;
		scanf("%d",&k);
		split(rt,k,x,y);
		rt=merge(merge(x,node(k)),y);
	}
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		split(rt,a[i].c-1,x,y);
		split(y,a[i].c+a[i].c-1,y,z);
		t2[z]+=a[i].c;
		v[z]-=a[i].c;
		t[z]++;
		s[z]++;
		while(!q.empty())
			q.pop();
		q.push(y);
		while(!q.empty())
		{
			int g=q.front();
			q.pop();
			pushdown(g);
			if(lc[g])
				q.push(lc[g]);
			if(rc[g])
				q.push(rc[g]);
			int b,c;
			split(x,v[g]-a[i].c,b,c);
			lc[g]=rc[g]=0;
			v[g]-=a[i].c;
			sz[g]=1;
			t[g]=t2[g]=0;
			s[g]++;
			x=merge(merge(b,g),c);
		}
		rt=merge(x,z);
	}
	print(rt);
	for(int i=1;i<=m;i++)
		printf("%d ",s[i]);
	return 0;
}//