#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
map<int,ll> x,y;
map<ll,ll> xy;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		x[a]+=1;
		y[b]+=1;
		xy[1LL*a*2.1e9+b]+=1;
	}
	ll ans = 0;
	for (auto p: x) {
		ans+=p.second*(p.second-1)/2;
	}
	for (auto p: y) {
		ans+=p.second*(p.second-1)/2;
	}
	for (auto p: xy) {
		ans-=p.second*(p.second-1)/2;
	}
	printf("%lld\n",ans);

	return 0;
}