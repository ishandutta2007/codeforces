#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,pos,a[N],x[N],q[N],t;
vector<pair<int,int>>ans;
void zh2()
{
	puts("-1");
	exit(0);
}
void zh1()
{
	for(int i=1;i<=n;i++)
		a[i]=x[i];
	for(int i=1;i<=n;i++)
		a[i]=max(a[i],a[i+1]);
	zh2();
}
namespace treap
{
	const int N=100005;
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
	r[cnt]=rand()*rand();
	return cnt;
}
void ins(int val)
{
	int x,y;
	split(rt,val,x,y);
	rt=merge(merge(x,node(val)),y);
}
void del(int val)
{
	int x,y,z;
	split(rt,val,x,y);
	split(x,val-1,x,z);
	z=merge(lc[z],rc[z]);
	rt=merge(merge(x,z),y);
}
int rnk(int val)
{
	int x,y;
	split(rt,val-1,x,y);
	return sz[x]+1;
	rt=merge(x,y);
}
int kth(int val)
{
	int x,y,z;
	Split(rt,val-1,x,y);
	Split(y,1,y,z);
	return v[y];
	rt=merge(merge(x,y),z);
}
int pre(int val)
{
	int x,y,z;
	split(rt,val-1,x,y);
	Split(x,sz[x]-1,x,z);
	return v[z];
	rt=merge(merge(x,z),y);
}
int suf(int val)
{
	int x,y,z;
	split(rt,val,x,y);
	Split(y,1,y,z);
	return v[y];
	rt=merge(x,merge(y,z));
}
}
int main()
{
	scanf("%d",&n);
	pos=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i;i--)
	{
		if(a[i]==1)
		{
			x[i]=pos;
			q[++t]=i;
			ans.emplace_back(pos--,i);
		}
		else if(a[i]==2)
		{
			if(t==0)
				zh2();
			x[i]=x[q[t--]];
			ans.emplace_back(x[i],i);
		}
	}
	for(int i=1;i<=n;i++) 
		if(a[i]==2) 
			q[++t]=i;
	sort(q+1,q+t+1);
	for(int i=n;i;i--)
	{
		if(a[i]==3)
		{
			if(t==0||q[t]<i)
				zh2();
			ans.emplace_back(pos,i);
			ans.emplace_back(pos--,q[t--]);
			q[++t]=i;
		}
	}
	printf("%d\n",ans.size());
	for(auto i:ans)
		printf("%d %d\n",i.first,i.second);
	return 0;
}