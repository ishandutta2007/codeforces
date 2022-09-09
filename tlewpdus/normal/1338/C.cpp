#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll a, b, c;
void getith(ll n) {
	ll step = 1;
	ll cur = 0;
	while(cur<n) {
		cur += step;
		step *= 4;
	}
	step/=4;
	cur -= step;
	a = step+(n-cur-1);
	ll p = n-cur-1;
	ll q = 0;
	ll cor[] = {0,2,3,1};
	for (ll i=1;i<=p;i*=4) {
		q |=cor[p/i%4]*i;
	}
	b = step*2+q;
	q = 0;
	ll tcor[] = {0,3,1,2};
	for (ll i=1;i<=p;i*=4) {
		q |=tcor[p/i%4]*i;
	}
	c = step*3+q;
}

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		ll n;
		scanf("%lld",&n);
		getith((n-1)/3+1);
		if (n%3==1) printf("%lld\n",a);
		else if (n%3==2) printf("%lld\n",b);
		else printf("%lld\n",c);
	}

	return 0;
}