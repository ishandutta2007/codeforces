#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
int a[max_n],Log[max_n];
long long s[max_n],f[2][19][max_n];
inline long long query(int k,int l,int r)
{
	int t=Log[r-l+1];
	return min(f[k][t][l],f[k][t][r-(1<<t)+1]);
}
long long Hash[max_n];
int len;
namespace SegTree
{
	int tot;
	const int max_tot=2*20*3e5+5;
	struct Node
	{
		int ls,rs,val;
	}node[max_tot];
	#define ls(p) node[p].ls
	#define rs(p) node[p].rs
	#define val(p) node[p].val
	void build(int &p,int old,int l,int r,int k,int v)
	{
		p=++tot;
		ls(p)=ls(old);
		rs(p)=rs(old);
		val(p)=val(old)+v;
		if(l<r)
		{
			int mid=(l+r)>>1;
			if(k<=mid)
				build(ls(p),ls(old),l,mid,k,v);
			else
				build(rs(p),rs(old),mid+1,r,k,v);
		}
	}
	int res;
	void query(int p,int q,int l,int r,int k)
	{
		if(l==r)
		{
			res=val(p)-val(q);
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid)
			query(ls(p),ls(q),l,mid,k);
		else
			query(rs(p),rs(q),mid+1,r,k);
	}
}
int root[2][max_n];
const long long inf=1e18;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		long long ans=0;
		for(int i=1;i<=n;++i) // len=1
		{
			if(!a[i])
				++ans;
		}
		for(int i=1;i+1<=n;++i) // len=2
		{
			if(a[i]==a[i+1])
				++ans;
		}
		for(int i=1;i<=n;++i)
		{
			s[i]=a[i]-s[i-1];
//			fprintf(stderr,"i=%d s[i]=%lld\n",i,s[i]);
			Hash[i]=s[i];
		}
		sort(Hash+1,Hash+n+1);
		len=unique(Hash+1,Hash+n+1)-Hash-1;
		SegTree::tot=0;
		for(int i=1;i<=n;++i)
		{
			int v=lower_bound(Hash+1,Hash+len+1,s[i])-Hash;
			assert(v<=len);
			for(int t=0;t<=1;++t)
				SegTree::build(root[t][i],root[t][i-1],1,len,v,i%2==t%2);
		}
		Log[0]=-1;
		for(int i=1;i<=n;++i)
			Log[i]=Log[i>>1]+1;
		assert(Log[n]<=18);
		for(int k=0;k<=1;++k)
		{
			for(int i=1;i<=n;++i)
			{
				if(i%2==k%2)
					f[k][0][i]=s[i];
				else
					f[k][0][i]=inf;
			}
			for(int i=1;i<=Log[n];++i)
				for(int j=1;j+(1<<i)-1<=n;++j)
					f[k][i][j]=min(f[k][i-1][j],f[k][i-1][j+(1<<(i-1))]);
		}
//		for(int i=1;i<=len;++i)
//			fprintf(stderr,"i=%d Hash[i]=%lld\n",i,Hash[i]);
		for(int L=n-2;L>=1;--L)
		{
			int l=L+1,r=n,res=L;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(query((L-1)&1,L,mid)>=s[L-1]&&query(((L-1)&1)^1,L,mid)>=-s[L-1])
					res=mid,l=mid+1;
				else
					r=mid-1;
			}
//			fprintf(stderr,"L=%d res=%d\n",L,res);
			if(res<L+2)
				continue;
			int v=lower_bound(Hash+1,Hash+len+1,s[L-1])-Hash;
//			fprintf(stderr,"v=%d\n",v);
			if(v<=len&&Hash[v]==s[L-1])
			{
				SegTree::query(root[(L-1)&1][res],root[(L-1)&1][L+1],1,len,v);
				ans+=SegTree::res;
//				fprintf(stderr,"(L-1)&1=%d\n",(L-1)&1);
//				fprintf(stderr,"L+1=%d res=%d\n",L+1,res);
//				fprintf(stderr,"v=%d S:res=%d\n",v,SegTree::res);
			}
			v=lower_bound(Hash+1,Hash+len+1,-s[L-1])-Hash;
			if(v<=len&&Hash[v]==-s[L-1])
			{
				SegTree::query(root[((L-1)&1)^1][res],root[((L-1)&1)^1][L+1],1,len,v);
				ans+=SegTree::res;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
4
1 1 1 1
---
4
*/