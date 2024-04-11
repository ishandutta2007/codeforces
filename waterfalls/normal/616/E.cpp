#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
int add(ll a, ll b) { return (a+b)%MOD; }
int sub(ll a, ll b) { return ((a-b)%MOD + MOD)%MOD; }
int mult(ll a, ll b) { return ((a%MOD) * (b%MOD))%MOD; }

int sumto(ll a) {
	if (a%2==0) return mult(a/2,a+1);
	else return mult(a,(a+1)/2);
}
int sum(ll a, ll b) { return sub(sumto(b),sumto(a-1)); }

ll n,m;

int main() {
	scanf("%lld%lld",&n,&m);
	int ans = 0;
	if (m>n) {
		ans = mult(n,m-n);
		m = n;
	}
	ll res = n;
	ll prev = 1;
	while (true) {
		ll next = m;
		if (res) next = min(next,n/res);
		ans = add(ans,mult(n,next-prev+1));
		ans = sub(ans,mult(res,sum(prev,next)));
		prev = next+1;
		res = n/prev;
		if (prev>m) break;
	}
	printf("%d\n",ans);

	return 0;
}