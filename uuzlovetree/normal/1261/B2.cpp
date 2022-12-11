#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,m;
int a[maxn];
int maxv[maxn<<2];
vector< pair<int,int> > q[maxn];
void pushup(int rt)
{
	maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
}
void build(int rt,int l,int r)
{
	if(l==r){maxv[rt]=a[l];return;}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
	pushup(rt); 
}
int update(int rt,int l,int r)
{
	if(l==r)
	{
		maxv[rt]=0;
		return l;
	}
	int mid=(l+r)>>1,ans=0;
	if(maxv[rt<<1]>=maxv[rt<<1|1])ans=update(rt<<1,l,mid);
	else ans=update(rt<<1|1,mid+1,r);
	pushup(rt);
	return ans;
}
int sz[maxn<<2];
void add(int rt,int l,int r,int pos)
{
	sz[rt]++;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(pos<=mid)add(rt<<1,l,mid,pos);
	else add(rt<<1|1,mid+1,r,pos);
}
int query(int rt,int l,int r,int k)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(k<=sz[rt<<1])return query(rt<<1,l,mid,k);
	else return query(rt<<1|1,mid+1,r,k-sz[rt<<1]);
}
int Ans[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		q[x].push_back(make_pair(y,i));
	}
	build(1,1,n);
	for(int i=1;i<=n;++i)
	{
		int x=update(1,1,n);
		add(1,1,n,x);
		for(auto u:q[i])
		{
			int k=u.first,id=u.second;
			Ans[id]=a[query(1,1,n,k)];
		}
	}
	for(int i=1;i<=m;++i)printf("%d\n",Ans[i]);
}