#include<bits/stdc++.h>
using namespace std;
int R;
const int max_n=2e5+5;
int tp[max_n],d[max_n],Hash[max_n];
namespace SegTree
{
	struct Node
	{
		int cnt;
		long long sum;
	}node[max_n<<2];
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	#define cnt(p) node[p].cnt
	#define sum(p) node[p].sum
	void modify(int p,int l,int r,int k,int v)
	{
		cnt(p)+=v,sum(p)+=Hash[k]*v;
		if(l<r)
		{
			int mid=(l+r)>>1;
			if(k<=mid)
				modify(ls(p),l,mid,k,v);
			else
				modify(rs(p),mid+1,r,k,v);
		}
	}
	long long res;
	void query(int p,int l,int r,int k)
	{
		if(l==r)
		{
			assert(cnt(p)>=k);
			res+=1ll*k*Hash[l];
			return;
		}
		int mid=(l+r)>>1;
		if(cnt(rs(p))>=k)
			query(rs(p),mid+1,r,k);
		else
		{
			res+=sum(rs(p));
			query(ls(p),l,mid,k-cnt(rs(p)));
		}
	}
	inline long long query(int k)
	{
		res=0;
		if(k>0)
			query(1,1,R,k);
		return res;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",tp+i,d+i);
		Hash[i]=d[i]>0?d[i]:-d[i];
	}
	sort(Hash+1,Hash+n+1);
	R=unique(Hash+1,Hash+n+1)-Hash-1;
	int cnt_double=0;
	set<int> F,L; 
	for(int i=1;i<=n;++i)
	{
		if(d[i]>0)
		{
			cnt_double+=tp[i];
			int k=lower_bound(Hash+1,Hash+R+1,d[i])-Hash;
			SegTree::modify(1,1,R,k,1);
			if(tp[i])
				L.insert(d[i]);
			else
				F.insert(d[i]);
		}
		else
		{
			cnt_double-=tp[i];
			int k=lower_bound(Hash+1,Hash+R+1,-d[i])-Hash;
			SegTree::modify(1,1,R,k,-1);
			if(tp[i])
				L.erase(-d[i]);
			else
				F.erase(-d[i]);
		}
		long long ans=SegTree::sum(1)+SegTree::query(cnt_double);
		if(!L.empty())
		{
			if(F.empty()||*L.begin()>*F.rbegin())
			{
				ans-=*L.begin();
				if(!F.empty())
					ans+=*F.rbegin();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}