#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int h[max_n];
const int max_q=1e5+5;
int opt[max_q],p[max_q],x[max_q];
long long v[max_q];
const int max_R=2e5+5;
int Hash[max_R],R;
template<class T> class BIT
{
	private:
		T val[max_R];
	public:
		inline void modify(int k,int v)
		{
			for(int i=k;i<=R;i+=i&(-i))
				val[i]+=v;
		}
		inline T query(int k)
		{
			T res=0;
			for(int i=k;i>0;i-=i&(-i))
				res+=val[i];
			return res;
		}
};
BIT<int> cnt;
BIT<long long> sum;
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",h+i);
		Hash[++R]=h[i];
	}
	for(int i=1;i<=q;++i)
	{
		scanf("%d",opt+i);
		if(opt[i]==1)
		{
			scanf("%d%d",p+i,x+i);
			Hash[++R]=x[i];
		}
		else
			scanf("%lld",v+i);
	}
	sort(Hash+1,Hash+R+1);
	R=unique(Hash+1,Hash+R+1)-Hash-1;
	for(int i=1;i<=n;++i)
	{
		h[i]=lower_bound(Hash+1,Hash+R+1,h[i])-Hash;
		cnt.modify(h[i],1);
		sum.modify(h[i],Hash[h[i]]);
	}
	const double eps=1e-6;
	for(int i=1;i<=q;++i)
	{
		if(opt[i]==1)
		{
			cnt.modify(h[p[i]],-1);
			sum.modify(h[p[i]],-Hash[h[p[i]]]);
			h[p[i]]=lower_bound(Hash+1,Hash+R+1,x[i])-Hash;
			cnt.modify(h[p[i]],1);
			sum.modify(h[p[i]],Hash[h[p[i]]]);
		}
		else
		{
			double l=0,r=1.0*v[i]/n+Hash[R],res=r;
			while(r-l>=eps)
			{
				double mid=(l+r)*0.5;
				int x=upper_bound(Hash+1,Hash+R+1,mid)-Hash-1;
				if(mid*cnt.query(x)-sum.query(x)>=v[i])
					res=mid,r=mid-eps;
				else
					l=mid+eps;
			}
			printf("%.5lf\n",res);
		}
	}
	return 0;
}