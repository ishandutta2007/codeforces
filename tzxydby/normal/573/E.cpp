#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],rt,c,lc[N],rc[N],sz[N],r[N];
long long tb[N],td[N],v[N],ans;
int newnode(long long val)
{
	c++;
	sz[c]=1,v[c]=val,r[c]=rand();
	return c;
}
void pushup(int x)
{
	sz[x]=sz[lc[x]]+sz[rc[x]]+1;
}
void pushdown(int x)
{
	if(tb[x])
	{
		if(lc[x])
			tb[lc[x]]+=tb[x];
		v[x]+=tb[x];
		if(rc[x])
			tb[rc[x]]+=tb[x];
		tb[x]=0;
	}
	if(td[x])
	{
		long long pr=1;
		if(lc[x])
		{
			pr+=sz[lc[x]];
			td[lc[x]]+=td[x];
		}
		v[x]+=pr*td[x];
		if(rc[x])
		{
			tb[rc[x]]+=pr*td[x];
			td[rc[x]]+=td[x];
		}
		td[x]=0;
	}
}
int merge(int a,int b)
{
	if(!a||!b) return a|b;
	pushdown(a),pushdown(b);
	if(r[a]>r[b])
	{
		rc[a]=merge(rc[a],b);
		pushup(a);
		return a;
	}
	else
	{
		lc[b]=merge(a,lc[b]);
		pushup(b);
		return b;
	}
}
void split(int u,int k,int &a,int &b)
{
	if(!u)
	{
		a=b=0;
		return;
	}
	pushdown(u);
	if(sz[lc[u]]+1<=k)
	{
		a=u;
		split(rc[u],k-sz[lc[u]]-1,rc[u],b);
	}
	else
	{
		b=u;
		split(lc[u],k,a,lc[u]);
	}
	pushup(u);
}
long long kth(int k)
{
	if(k<0) return 0;
	int x,y,z;
	split(rt,k,x,y);
	split(y,1,y,z);
	long long val=v[y];
	rt=merge(x,merge(y,z));
	return val;
}
void sol(int x)
{
	if(!x) return;
	pushdown(x);
	ans=max(ans,v[x]);
	sol(lc[x]);
	sol(rc[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	rt=merge(newnode(0),newnode(a[1]));
	for(int i=2;i<=n;i++)
	{
		int l=0,r=i;
		while(r-l>1)
		{
			int m=l+r>>1;
			if(kth(m-1)+1ll*m*a[i]>=kth(m))
				r=m;
			else
				l=m;
		}
		int x,y,z;
		split(rt,r,x,z);
		split(x,r-1,x,y);
		x=merge(x,newnode(v[y]));
		z=merge(y,z);
		tb[z]+=1ll*(r-1)*a[i];
		td[z]+=a[i];
		rt=merge(x,z);
	}
	sol(rt);
	printf("%lld\n",ans);
	return 0;
}