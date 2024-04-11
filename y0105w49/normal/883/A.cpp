// ayy
// ' lamo
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=2LL*inf*inf;
const int P=1e9+7;



ll n,a,d;
int m;
vector<ll> t;

ll Z=0;
ll pr=-linf;

void go(ll x) {
	// cerr<<x<<endl;
	if(x<=a || x>a*n) {
		if(pr+d >= x) return;
		++Z, pr=x;
		return;
	}
	if(pr+d >= x) return;
	// a <= pr < pr+d < x <= a*n

	pr+=d;
	pr-=pr%a;
	pr+=a;
	++Z;
	pr=min(pr,x);

	if(pr+d >= x) return;
	assert(!(pr%a));

	ll per=d/a+1;
	ll K=(x-pr)/(a*per);
	// K=max(K-4,0LL);
	Z+=K;
	pr+=K*a*per;
	return go(x);
}





int32_t main() {
	scanf("%lld%d%lld%lld",&n,&m,&a,&d);
	for(int i=0;i<m;i++) {
		ll x; scanf("%lld",&x); t.pb(x);
	}
	t.pb(a);
	t.pb(a*n);
	t.pb(a);
	t.pb(a*n);
	sort(t.begin(),t.end());

	for(ll x:t) go(x);
	printf("%lld\n",Z);
}