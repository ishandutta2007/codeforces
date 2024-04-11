#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
#define ll long long
const int N=100050;
const ll inf=(ll)1000000000*N;
vector<ll> pows;
ll aps(ll x){ return x>0?x:-x;}
void AddPows(ll k)
{
	if(k==1)
	{
		pows.push_back(1);
		return;
	}
	if(k==-1)
	{
		pows.push_back(1);
		pows.push_back(-1);
		return;
	}
	ll x=1;
	while(aps(x)<inf)
	{
		pows.push_back(x);
		x*=k;
	}
}
map<ll,int> cnt;
ll dp[N],sol;
int a[N];
int main()
{
	int n,k,i,j;
	scanf("%i %i",&n,&k);
	AddPows(k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),dp[i]=dp[i-1]+a[i];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<pows.size();j++) if(cnt.count(dp[i]-pows[j])) sol+=cnt[dp[i]-pows[j]];
		cnt[dp[i]]++;
	}
	printf("%lld\n",sol);
	return 0;
}