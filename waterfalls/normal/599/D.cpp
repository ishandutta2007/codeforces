#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x;

ll sum2(ll a) { return a*(a+1)*(2*a+1)/6; }
ll sum1(ll a) {	return a*(a+1)/2; }

ll cnt(ll a, ll b) {
	ll tot = a*b*a;
	tot-=b*sum1(a-1);
	tot-=a*sum1(a-1);
	tot+=sum2(a-1);
	return tot;
}

int main() {
	scanf("%lld",&x);
	vector<pair<ll,ll> > ans;
	for (ll i=1;;i++) {
		if (sum2(i)>x) break;
		ll low = i-1;
		ll high = 4e18/i/i;
		while (high-low>1) {
			if (cnt(i,(low+high+1)/2)>=x) high = (low+high+1)/2;
			else low = (low+high+1)/2;
		}
		if (cnt(i,high)==x) {
			ans.push_back(make_pair(i,high));
			if (i!=high) ans.push_back(make_pair(high,i));
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for (auto i: ans) printf("%lld %lld\n",i.first,i.second);

	return 0;
}