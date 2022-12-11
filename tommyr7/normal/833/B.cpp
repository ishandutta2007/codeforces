#include <bits/stdc++.h>
#define Maxn 35007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct seg
{
	int lx,rx;
	int mx,tag;
};
int n,k;
int a[Maxn],pre[Maxn],last[Maxn];
int f[Maxn];
bool vis[Maxn];
seg tree[Maxn*4];
void build(int node,int lx,int rx)
{
	tree[node].lx=lx,tree[node].rx=rx;
	tree[node].tag=0,tree[node].mx=0;
	if (lx==rx) return;
	int mid=(lx+rx)/2;
	build(node*2,lx,mid);
	build(node*2+1,mid+1,rx);
}
void pushdown(int node)
{
	if (tree[node].tag==0) return;
	tree[node*2].mx+=tree[node].tag;
	tree[node*2].tag+=tree[node].tag;
	tree[node*2+1].mx+=tree[node].tag;
	tree[node*2+1].tag+=tree[node].tag;
	tree[node].tag=0;
}
int query(int node,int l,int r)
{
	if (tree[node].rx<l||tree[node].lx>r) return 0;
	if (tree[node].lx>=l&&tree[node].rx<=r) return tree[node].mx;
	pushdown(node);
	return max(query(node*2,l,r),query(node*2+1,l,r));
}
void update(int node,int pos,int val)
{
	if (tree[node].rx<pos||tree[node].lx>pos) return;
	if (tree[node].lx==pos&&tree[node].rx==pos)
	{
		tree[node].mx=val;
		tree[node].tag=0;
		return;
	}
	pushdown(node);
	update(node*2,pos,val);
	update(node*2+1,pos,val);
	tree[node].mx=max(tree[node*2].mx,tree[node*2+1].mx);
}
void update2(int node,int l,int r)
{
	if (tree[node].rx<l||tree[node].lx>r) return;
	if (tree[node].lx>=l&&tree[node].rx<=r)
	{
		tree[node].mx+=1;
		tree[node].tag+=1;
		return;
	}
	pushdown(node);
	update2(node*2,l,r);
	update2(node*2+1,l,r);
	tree[node].mx=max(tree[node*2].mx,tree[node*2+1].mx);
}
int main()
{
	n=read(),k=read();
	memset(a,0,sizeof(a));
	memset(last,0,sizeof(last));
	memset(pre,0,sizeof(pre));
	build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		last[i]=pre[a[i]];
		pre[a[i]]=i;
	}
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if (last[i]==0) ++f[i];
		update(1,i,f[i]+1);
	}
	for (int j=2;j<=k;j++)
	{
		for (int i=j;i<=n;i++)
		{
			if (i-2>0&&last[i]<i-1) update2(1,max(last[i],j-1),i-2);
			f[i]=query(1,j-1,i-1);
		}
		for (int i=j;i<=n;i++)
			update(1,i,f[i]+1);
	}
	printf("%d\n",f[n]);
	return 0;
}