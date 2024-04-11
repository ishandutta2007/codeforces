#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dist(ll x1, ll y1, ll x2, ll y2) {
	return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

int n;
ll x1,y1,x2,y2;
ll x[2013], y[2013];
ll ans = 1e18;

void test(ll d) {
	ll oth = 0;
	for (int i=0;i<n;i++) {
		if (dist(x1,y1,x[i],y[i])>d) oth = max(oth,dist(x2,y2,x[i],y[i]));
	}
	ans = min(ans,oth+d);
}

int main() {
	scanf("%d",&n);
	scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
	for (int i=0;i<n;i++) scanf("%lld%lld",&x[i],&y[i]);
	test(0);
	for (int i=0;i<n;i++) test(dist(x1,y1,x[i],y[i]));
	printf("%lld\n",ans);

	return 0;
}