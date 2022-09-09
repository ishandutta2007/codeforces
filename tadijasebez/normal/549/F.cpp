#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
set<int> out;
vector<pair<int,int> > work;
const int N=300050;
const int M=1000050;
int a[N],sum[N],cnt[M];
struct Query
{
	int mul,o;
	Query(int b=0, int e=0){ mul=b,o=e;}
};
vector<Query> Qs[N];
int main()
{
	int n,i,k;
	scanf("%i %i",&n,&k);out.insert(0);out.insert(n+1);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),sum[i]=(sum[i-1]+a[i])%k,work.pb(mp(-a[i],i));
	sort(work.begin(),work.end());
	for(auto p:work)
	{
		i=p.second;
		int r=*out.upper_bound(i)-1;
		int l=*--out.upper_bound(i)+1;
		out.insert(i);
		int d=a[i]%k;
		//printf("%i - %i - %i\n",l,i,r);
		if(i-l<=r-i)
		{
			for(int j=l;j<=i;j++)
			{
				int o=d+sum[j-1];
				while(o>=k) o-=k;
				//printf("(%i %i) %i %i\n",i,r,j,o);
				Qs[i-1].pb(Query(-1,o));
				Qs[r].pb(Query(1,o));
			}
		}
		else
		{
			for(int j=i;j<=r;j++)
			{
				int o=sum[j]-d;
				while(o<0) o+=k;
				//printf("(%i %i) %i %i\n",l-1,i-1,j,o);
				if(l-2>=0) Qs[l-2].pb(Query(-1,o));
				Qs[i-1].pb(Query(1,o));
			}
		}
	}
	ll ans=-n;
	for(i=0;i<=n;i++)
	{
		cnt[sum[i]]++;
		//printf("%i ",sum[i]);
		for(Query p:Qs[i]) ans+=p.mul*cnt[p.o];
	}
	printf("%lld\n",ans);
	return 0;
}