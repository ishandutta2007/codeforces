#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int mod=1e9+7;
const int N=1000050;
int a[N];
vector<pair<int,int> > work;
set<int> out;
int calc(int l, int r, int k, int o)
{
	printf("%i %i %i=%i\n",l,r,o,max((r+k-o)/k-(l+k-o-1)/k,0));
	return max((r+k-o)/k-(l+k-o-1)/k,0);
}
void add(int &x, int y){ x+=y;if(x>=mod) x-=mod;}
ll dp[N];
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	out.insert(0);out.insert(n+1);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),work.pb(mp(-a[i],i));
	sort(work.begin(),work.end());
	int ans=0;
	for(i=1;i<=n;i++) dp[i]=i<k?0:dp[i-k+1]+i-k+1,dp[i]%=mod;
	for(auto h:work)
	{
		i=h.second;
		auto it=out.upper_bound(i);
		int r=*it-1;--it;int l=*it+1;
		//printf("%i - %i - %i\n",l,i,r);
		ll mul=dp[r-l+1]-dp[i-l]-dp[r-i];
		while(mul<0) mul+=mod;
		add(ans,(ll)mul*a[i]%mod);
		/*if(i-l<r-i)
		{
			for(int j=l;j<=i;j++) add(ans,(ll)calc(i+1,r+1,k,j%k)*a[i]%mod);
		}
		else
		{
			for(int j=i;j<=r;j++) add(ans,(ll)calc(l-1,i-1,k,j%k)*a[i]%mod);
		}*/
		out.insert(i);
	}
	printf("%i\n",ans);
	return 0;
}