#include <bits/stdc++.h>
using namespace std;
const int N=200050;
const int inf=1e9+7;
struct SegmentTree
{
	vector<int> mx;
	int sz;
	void init(int n){ mx.assign(n*2,-inf);sz=n;}
	void Set(int i, int f){ i+=sz-1;mx[i]=f;for(i>>=1;i;i>>=1) mx[i]=max(mx[i<<1],mx[i<<1|1]);}
	int Get(int l, int r)
	{
		int ans=-inf;
		for(l+=sz-1,r+=sz-1;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ans=max(ans,mx[l++]);
			if(r%2==0) ans=max(ans,mx[r--]);
		}
		return ans;
	}
} ST[32];
int main()
{
	int n,k,q,i,j,all,t,l,r;
	scanf("%i %i",&n,&k);all=(1<<k)-1;
	for(i=0;i<1<<k;i++) ST[i].init(n);
    for(i=1;i<=n;i++)
	{
		vector<int> x(k);
		for(j=0;j<k;j++) scanf("%i",&x[j]);
		for(int mask=0;mask<1<<k;mask++)
		{
			int sum=0;
			for(j=0;j<k;j++) sum+=(((mask>>j)&1)?1:-1)*x[j];
			ST[mask].Set(i,sum);
		}
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i",&i);
			vector<int> x(k);
			for(j=0;j<k;j++) scanf("%i",&x[j]);
			for(int mask=0;mask<1<<k;mask++)
			{
				int sum=0;
				for(j=0;j<k;j++) sum+=(((mask>>j)&1)?1:-1)*x[j];
				ST[mask].Set(i,sum);
			}
		}
		else
		{
			scanf("%i %i",&l,&r);
			int ans=-inf;
			for(int mask=0;mask<1<<(k-1);mask++)
			{
				ans=max(ans,ST[mask].Get(l,r)+ST[all^mask].Get(l,r));
			}
			printf("%i\n",ans);
		}
	}
	return 0;
}