#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;
const ll INF = 1e18;

int n,m;
ll a[2013], b[2013];
ll diff;

vector<ll> getzero() {
	return { abs(diff) };
}
vector<ll> getone() {
	vector<ll> res = { INF };
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
		ll cur = abs(diff-2*a[i]+2*b[j]);
		res = min(res,{ cur,i,j });
	}
	return res;
}
vector<ll> gettwo() {
	vector<ll> res = { INF };
	set<pair<ll,pair<int,int> > > has;
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) {
		has.insert(MP(2*a[i]+2*a[j],MP(i,j)));
	}
	for (int i=1;i<=m;i++) for (int j=i+1;j<=m;j++) {
		ll cur = diff+2*b[i]+2*b[j];
		auto it = has.lower_bound(MP(cur,MP(0,0)));
		if (it!=has.end()) {
			res = min(res,{ abs(cur-it->A),it->B.A,i,it->B.B,j });
		}
		if (it!=has.begin()) {
			it = --it;
			res = min(res,{ abs(cur-it->A),it->B.A,i,it->B.B,j });
		}
	}
	return res;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%lld",&b[i]);
	diff = accumulate(a,a+n+1,0LL)-accumulate(b,b+m+1,0LL);
	vector<ll> res = min(min(getzero(),getone()),gettwo());
	printf("%lld\n",res[0]);
	printf("%d\n",res.size()/2);
	for (int i=1;i<res.size();i+=2) printf("%lld %lld\n",res[i],res[i+1]);

	return 0;
}