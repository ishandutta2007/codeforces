#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Tree
{
	#define lc x<<1
	#define rc x<<1|1
	#define mid ((l+r)>>1)
	struct Node
	{
		int sum;
		int minp;
	}tree[4000005];
	void pushup(int x)
	{
		tree[x].sum=tree[lc].sum+tree[rc].sum;
		tree[x].minp=min(tree[lc].minp,tree[rc].minp);
	}
	void build(int x,int l,int r)
	{
		tree[x].minp=2147483647;
		if(l==r)return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void ins(int x,int l,int r,int p)
	{
		if(p<l||p>r)return;
		if(l==r)
		{
			tree[x].sum=1;
			tree[x].minp=l;
			return;
		}
		if(p<=mid)ins(lc,l,mid,p);
		else ins(rc,mid+1,r,p);
		pushup(x);
	}
	void del(int x,int l,int r,int p)
	{
		if(p<l||p>r)return;
		if(l==r)
		{
			tree[x].sum=0;
			tree[x].minp=2147483647;
			return;
		}
		if(p<=mid)del(lc,l,mid,p);
		else del(rc,mid+1,r,p);
		pushup(x);
	}
	int query(int x,int l,int r,int p)
	{
		if(l==r)return tree[x].sum?l:l-1;
		if(p<=mid)return query(lc,l,mid,p);
		else if(tree[rc].minp<p)return query(rc,mid+1,r,p);
		else return query(lc,l,mid,p);
	}
	#undef lc
	#undef rc
	#undef mid
}T;
int n,q,nxt[1000005],col[1000005];
ll tag[1000005],c[1000005];
char s[15];
void add(int p,ll x)
{
	while(p<=n)
	{
		c[p]+=x;
		p+=p^(p&(p-1));
	}
}
ll sum(int x)
{
	ll ans=0;
	while(x)
	{
		ans+=c[x];
		x&=x-1;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&q);
	T.build(1,1,n);
	T.ins(1,1,n,1);
	nxt[0]=1;
	nxt[1]=n+1;
	col[1]=1;
	while(q--)
	{
		scanf("%s",s);
		int l,r,cc;
		if(s[0]=='C')
		{
			scanf("%d%d%d",&l,&r,&cc);
			int st=T.query(1,1,n,l);
			int x=nxt[st];
			if(x>r)
			{
				add(l,tag[col[st]]-tag[cc]);
				add(r+1,-tag[col[st]]+tag[cc]);
				T.ins(1,1,n,l);
				if(x>r+1)T.ins(1,1,n,r+1);
				nxt[st]=l,nxt[l]=r+1;
				if(x>r+1)nxt[r+1]=x,col[r+1]=col[st];
				col[l]=cc;
			}
			else
			{
				add(l,tag[col[st]]);
				add(x,-tag[col[st]]);
				int last=col[x];
				while(x<r+1)
				{
					last=col[x];
					add(x,tag[last]);
					T.del(1,1,n,x);
					x=nxt[x];
					add(min(x,r+1),-tag[last]);
				}
				T.ins(1,1,n,l);
				if(x>r+1)T.ins(1,1,n,r+1);
				nxt[st]=l,nxt[l]=r+1;
				if(x>r+1)nxt[r+1]=x,col[r+1]=last;
				col[l]=cc;
				add(l,-tag[cc]);
				add(r+1,tag[cc]);
			}
		}
		if(s[0]=='A')
		{
			scanf("%d%d",&l,&r);
			tag[l]+=r;
		}
		if(s[0]=='Q')
		{
			scanf("%d",&l);
			int x=T.query(1,1,n,l);
			if(nxt[x]<=l)x=nxt[x];
			printf("%lld\n",sum(l)+tag[col[x]]);
		}
	}
	return 0;
}