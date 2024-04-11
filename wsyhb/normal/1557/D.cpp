#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int max_len=6e5+5;
int Hash[max_len],len;
namespace SegmentTree
{
	struct Node
	{
		P val,lazy;
	}node[max_len<<2];
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	#define val(p) node[p].val
	#define lazy(p) node[p].lazy
	inline void push_down(int p)
	{
		val(ls(p))=max(val(ls(p)),lazy(p));
		val(rs(p))=max(val(rs(p)),lazy(p));
		lazy(ls(p))=max(lazy(ls(p)),lazy(p));
		lazy(rs(p))=max(lazy(rs(p)),lazy(p));
		lazy(p)=P(0,0);
	}
	P res;
	void query(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			res=max(res,val(p));
			return;
		}
		if(lazy(p).first||lazy(p).second)
			push_down(p);
		int mid=(l+r)>>1;
		if(a<=mid)
			query(ls(p),l,mid,a,b);
		if(b>mid)
			query(rs(p),mid+1,r,a,b);
	}
	inline P query(int a,int b)
	{
		res=P(0,0);
		query(1,1,len,a,b);
		++res.first;
		return res;
	}
	void modify(int p,int l,int r,int a,int b,P v)
	{
		if(a<=l&&r<=b)
		{
			val(p)=max(val(p),v);
			lazy(p)=max(lazy(p),v);
			return;
		}
		if(lazy(p).first||lazy(p).second)
			push_down(p);
		int mid=(l+r)>>1;
		if(a<=mid)
			modify(ls(p),l,mid,a,b,v);
		if(b>mid)
			modify(rs(p),mid+1,r,a,b,v);
		val(p)=max(val(ls(p)),val(rs(p)));
	}
}
const int max_n=3e5+5;
vector<P> Segment[max_n];
P dp[max_n];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int i,l,r;
		scanf("%d%d%d",&i,&l,&r);
		Hash[++len]=l,Hash[++len]=r;
		Segment[i].push_back(P(l,r));
	}
	sort(Hash+1,Hash+len+1);
	len=unique(Hash+1,Hash+len+1)-Hash-1;
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		dp[i]=P(1,0);
		for(vector<P>::iterator it=Segment[i].begin();it!=Segment[i].end();++it)
		{
			it->first=lower_bound(Hash+1,Hash+len+1,it->first)-Hash;
			it->second=lower_bound(Hash+1,Hash+len+1,it->second)-Hash;
			dp[i]=max(dp[i],SegmentTree::query(it->first,it->second));
		}
		if(dp[i]>dp[ans])
			ans=i;
		P copy=dp[i];
		dp[i].second=i;
		for(vector<P>::iterator it=Segment[i].begin();it!=Segment[i].end();++it)
			SegmentTree::modify(1,1,len,it->first,it->second,dp[i]);
		dp[i]=copy;
	}
	vector<int> Ans;
	for(int i=n;i>=ans+1;--i)
		Ans.push_back(i);
	for(int i=ans;i;i=dp[i].second)
		for(int j=i-1;j>=dp[i].second+1;--j)
			Ans.push_back(j);
//	fprintf(stderr,"Ans.size()=%d\n",(int)Ans.size());
	assert((int)Ans.size()==n-dp[ans].first);
	printf("%d\n",n-dp[ans].first);
	for(int i=0;i<int(Ans.size());++i)
		printf("%d%c",Ans[i],i+1<int(Ans.size())?' ':'\n');
	return 0;
}