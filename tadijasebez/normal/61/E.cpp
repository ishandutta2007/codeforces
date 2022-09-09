#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=1000050;
int a[N],l[N],r[N];
struct BIT
{
	int sum[N];
	void init()
	{
		for(int i=0;i<N;i++) sum[i]=0;
	}
	BIT(){ init();}
	void Set(int x, int y)
	{
		for(int i=x;i<N;i+=i&-i) sum[i]+=y;
	}
	int GetPrefix(int x)
	{
		int ans=0;
		for(int i=x;i>0;i-=i&-i) ans+=sum[i];
		return ans;
	}
	int GetRange(int l, int r)
	{
		return GetPrefix(r)-GetPrefix(l-1);
	}
} ST;
int main()
{
	int n;
	scanf("%i",&n);
	vector<int> all;
	for(int i=1;i<=n;i++) scanf("%i",&a[i]),all.pb(a[i]);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=1;i<=n;i++) a[i]=lower_bound(all.begin(),all.end(),a[i])-all.begin()+1;
	ST.init();
	for(int i=1;i<=n;i++)
	{
		l[i]=ST.GetRange(a[i]+1,all.size());
		ST.Set(a[i],1);
	}
	ST.init();
	for(int i=n;i>=1;i--)
	{
		r[i]=ST.GetRange(1,a[i]-1);
		ST.Set(a[i],1);
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=(ll)l[i]*r[i];
	printf("%lld\n",ans);
	return 0;
}