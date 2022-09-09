#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll d, m;

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%lld%lld",&d,&m);
		ll ans = 1;
		ll td = d;
		int c = 0;
		while(td) {
			td/=2;
			c++;
		}
		c--;
		while(d) {
			ans = ans*(d-(1LL<<c)+2)%m;
			d = (1LL<<c)-1; c--;
		}
		printf("%lld\n",(ans+m-1)%m);
	}

	return 0;
}