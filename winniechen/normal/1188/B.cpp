#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300005;
map<ll , ll >mp;
map<ll , ll >::iterator it;
pair<ll , ll >a[N];int n,p,k;
inline ll p4(int x){return (ll)x*x%p*x%p*x%p;}
inline ll val(pair<ll ,ll > x){return ((x.first*k%p-x.second)%p+p)%p;}
inline ll C2(ll x){return x*(x-1)/2;}
int main()
{
	scanf("%d%d%d",&n,&p,&k);
	for(int i=0;i<n;i++)scanf("%lld",&a[i].first),a[i].second=p4(a[i].first);
	for(int i=0;i<n;i++)mp[val(a[i])]++;ll ans=0;
	for(it=mp.begin();it!=mp.end();it++)ans+=C2((*it).second);
	printf("%lld\n",ans);
}