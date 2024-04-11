#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,Q,head[N],num,size[N],fa[N],ms[N],top[N],dfn[N],cnt,dep[N],val[N],ans,rt,root[N],lson[N<<6],rson[N<<6],sum[N<<6],pos[N],q[N];
struct edge
{
	int to,next;
	void add(int x,int y)
	{
		to=y,next=head[x],head[x]=num;
	}
}e[N<<1];
int read()
{
	int x=1;
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9') if(ch=='-') x=-1;
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9') s=s*10+ch-'0';
	return s*x;
}
void dfs(int x)
{
	size[x]=1;
	dep[x]=dep[fa[x]]+1;
	for(int i=head[x];i;i=e[i].next)
	{
		fa[e[i].to]=x;
		dfs(e[i].to);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>size[ms[x]]) 
			ms[x]=e[i].to;
	}
}
void Dfs(int x,int y)
{
	top[x]=y;
	pos[dfn[x]=++cnt]=x;
	if(ms[x]) 
		Dfs(ms[x],y);
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=ms[x]) 
			Dfs(e[i].to,e[i].to);
}
void ins(int &cur,int l,int r,int x,int last)
{
	cur=++cnt;
	lson[cur]=lson[last];
	rson[cur]=rson[last];
	sum[cur]=sum[last]+1;
	int mid=l+r>>1;
	if(l==r) return;
	if(x<=mid) ins(lson[cur],l,mid,x,lson[last]);
	else ins(rson[cur],mid+1,r,x,rson[last]);
}
int qry(int cur1,int cur2,int l,int r,int L,int R)
{
	if(L>R) return 0;
	if(L<=l&&R>=r) return sum[cur2]-sum[cur1];
	int ret=0,mid=l+r>>1;
	if(L<=mid) ret+=qry(lson[cur1],lson[cur2],l,mid,L,R);
	if(R>mid) ret+=qry(rson[cur1],rson[cur2],mid+1,r,L,R);
	return ret;
}
int lca(int x,int y)
{
	for(;top[x]!=top[y];x=fa[top[x]])
		if(dep[top[x]]<dep[top[y]]) 
			swap(x,y);
	return dep[x]<dep[y]?x:y;
}
int qry(int x,int y,int k,int year,int now)
{
	int z=lca(x,y);
	for(;dep[top[x]]>dep[z];x=fa[top[x]])
	{
		int tmp=dfn[x]-dfn[top[x]]+1-qry(root[year],root[now],1,n,dfn[top[x]],dfn[x]);
		if(tmp>=k)
		{
			int l=dfn[top[x]],r=dfn[x],ret=0;
			while(l<=r)
			{
				int mid=l+r>>1;
				int temp=dfn[x]-mid+1-qry(root[year],root[now],1,n,mid,dfn[x]);
				if(temp>=k) 
					ret=mid,l=mid+1;
				else 
					r=mid-1;
			}
			if(pos[ret]==y) 
				return -1;
			return pos[ret];
		}
		else k-=tmp;
	}
	int tmp=dfn[x]-dfn[z]+1-qry(root[year],root[now],1,n,dfn[z],dfn[x]);
	if(tmp>=k)
	{
		int l=dfn[z],r=dfn[x],ret=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			int temp=dfn[x]-mid+1-qry(root[year],root[now],1,n,mid,dfn[x]);
			if(temp>=k) 
				ret=mid,l=mid+1;
			else 
				r=mid-1;
		}
		if(pos[ret]==y) 
			return -1;
		return pos[ret];
	}
	else 
		k-=tmp;
	int yy=y,num=0;
	for(;dep[top[yy]]>dep[z];yy=fa[top[yy]])
		q[++num]=yy;
	tmp=dfn[yy]-dfn[z]-qry(root[year],root[now],1,n,dfn[z]+1,dfn[yy]);
	if(tmp>=k)
	{
		int l=dfn[z]+1,r=dfn[yy],ret=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			int temp=mid-dfn[z]-qry(root[year],root[now],1,n,dfn[z]+1,mid);
			if(temp>=k) 
				ret=mid,r=mid-1;
			else 
				l=mid+1;
		}
		if(pos[ret]==y) 
			return -1;
		return pos[ret];
	}
	else 
		k-=tmp;
	for(int i=num;i;i--)
	{
		int tmp=dfn[q[i]]-dfn[top[q[i]]]+1-qry(root[year],root[now],1,n,dfn[top[q[i]]],dfn[q[i]]);
		if(tmp>=k)
		{
			int l=dfn[top[q[i]]],r=dfn[q[i]],ret=0;
			while(l<=r)
			{
				int mid=l+r>>1;
				int temp=mid-dfn[top[q[i]]]+1-qry(root[year],root[now],1,n,dfn[top[q[i]]],mid);
				if(temp>=k) 
					ret=mid,r=mid-1;
				else 
					l=mid+1;
			}
			if(pos[ret]==y) 
				return -1;
			return pos[ret];
		}
		else 
			k-=tmp;
	}
	return -1;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		fa[i]=read();
		if(fa[i]==0) 
			rt=i;
		e[++num].add(fa[i],i);
	}
	dfs(rt);
	Dfs(rt,rt);
	cnt=0;
	Q=read();
	for(int i=1;i<=Q;i++)
	{
		int op=read();
		if(op==1)
		{
			int x=read();
			val[x]=i;
			ins(root[i],1,n,dfn[x],root[i-1]);
		}
		else
		{
			root[i]=root[i-1];
			int x=read(),y=read(),k=read(),year=read();
			if(val[x]<=year) k++;
			printf("%d\n",qry(x,y,k,year,i));
		}
	}
	return 0;
}