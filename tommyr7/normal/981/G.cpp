#include <bits/stdc++.h>
#define Maxn 2000007
#define modp 998244353
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,q;
struct node
{
	int lx,rx;
	long long tag1,tag2;
	long long sum;
} tree[Maxn];
set<pair<int,int> >s[Maxn+7];
set<pair<int,int> >::iterator it,it1,it2,it3;
int bin[Maxn];
void build(int node,int lx,int rx)
{
	tree[node].lx=lx,tree[node].rx=rx;
	tree[node].tag1=0,tree[node].tag2=0;
	tree[node].sum=0;
	if (lx==rx) return;
	int mid=(lx+rx)/2;
	build(node*2,lx,mid);
	build(node*2+1,mid+1,rx);
}
void push_down(int node)
{
	if (tree[node].tag2)
	{
		int del=bin[tree[node].tag2];
		tree[node*2].tag1=(1LL*del*tree[node*2].tag1)%modp;
		tree[node*2].tag2+=tree[node].tag2;
		tree[node*2].sum=(1LL*del*tree[node*2].sum)%modp;
		tree[node*2+1].tag1=(1LL*del*tree[node*2+1].tag1)%modp;
		tree[node*2+1].tag2+=tree[node].tag2;
		tree[node*2+1].sum=(1LL*del*tree[node*2+1].sum)%modp;
		tree[node].tag2=0;
	}
	if (tree[node].tag1)
	{
		tree[node*2].tag1+=tree[node].tag1;
		tree[node*2].sum=(tree[node*2].sum+1LL*tree[node].tag1*(tree[node*2].rx-tree[node*2].lx+1))%modp;
		tree[node*2+1].tag1+=tree[node].tag1;
		tree[node*2+1].sum=(tree[node*2+1].sum+1LL*tree[node].tag1*(tree[node*2+1].rx-tree[node*2+1].lx+1))%modp;
		tree[node].tag1=0;
	}
}
int query(int node,int lx,int rx)
{
	if (tree[node].lx>rx||tree[node].rx<lx) return 0;
	push_down(node);
	if (tree[node].lx>=lx&&tree[node].rx<=rx) return tree[node].sum;
	return (query(node*2,lx,rx)+query(node*2+1,lx,rx))%modp;
}
void update1(int node,int lx,int rx)
{
	if (tree[node].lx>rx||tree[node].rx<lx) return;
	push_down(node);
	if (tree[node].lx>=lx&&tree[node].rx<=rx)
	{
		tree[node].sum=(tree[node].sum+tree[node].rx-tree[node].lx+1)%modp;
		++tree[node].tag1;
		return;
	}
	update1(node*2,lx,rx);
	update1(node*2+1,lx,rx);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%modp;
}
void update2(int node,int lx,int rx)
{
	if (tree[node].lx>rx||tree[node].rx<lx) return;
	push_down(node);
	if (tree[node].lx>=lx&&tree[node].rx<=rx)
	{
		tree[node].sum=(tree[node].sum+tree[node].sum)%modp;
		++tree[node].tag2;
		tree[node].tag1=(tree[node].tag1+tree[node].tag1)%modp;
		return;
	}
	update2(node*2,lx,rx);
	update2(node*2+1,lx,rx);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%modp;
}
signed main()
{
	bin[0]=1;
	for (int i=1;i<=2000000;i++)
		bin[i]=(2LL*bin[i-1])%modp;
	n=read(),q=read();
	build(1,1,n);
	while (q--)
	{
		int op=read();
		if (op==1)
		{
			int lx=read(),rx=read(),val=read();
			it=s[val].lower_bound(make_pair(lx,0));
			if (it!=s[val].begin())
			{
				it1=it;
				--it1;
				if ((*it1).second<lx) ++it1;
			} else it1=it;
			it2=s[val].lower_bound(make_pair(rx,0));
			if (it2!=s[val].begin()&&it2!=s[val].end()&&(*it2).first>rx) --it2;
			if (it1==s[val].end()||(*it1).first>rx)
			{
				update1(1,lx,rx);
				s[val].insert(make_pair(lx,rx));
			} else
			{
				if (it2!=s[val].end()) ++it2;
				if ((*it1).first>lx) update1(1,lx,(*it1).first-1);
				for (it=it1;it!=it2;it++)
				{
					update2(1,max((*it).first,lx),min((*it).second,rx));
					it3=it;
					++it3;
					if (it3!=s[val].end()&&(*it).second+1<=min(rx,(*it3).first-1)) update1(1,(*it).second+1,min((*it3).first-1,rx));
					else if (it3==s[val].end()&&(*it).second+1<=rx) update1(1,(*it).second+1,rx);
				}
				for (it=it1;it!=it2;)
				{
					it3=it;
					++it;
					lx=min(lx,(*it3).first);
					rx=max(rx,(*it3).second);
					s[val].erase(it3);
				}
				s[val].insert(make_pair(lx,rx));
			}
		} else
		{
			int lx=read(),rx=read();
			printf("%lld\n",query(1,lx,rx));
		}
	}
	return 0;
}