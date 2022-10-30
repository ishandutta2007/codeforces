#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,b;
queue<ll> has;
ll ans[200013];

int main() {
	scanf("%d%d",&n,&b);
	for (int i=0;i<n;i++) {
		ll t,d;
		scanf("%lld%lld",&t,&d);
		while (has.size() && has.front()<=t) {
			has.pop();
		}
		if (has.size()>b) ans[i] = -1;
		else {
			t+=d;
			if (has.size()) t = max(t,has.back()+d);
			has.push(t);
			ans[i] = t;
		}
	}
	for (int i=0;i<n;i++) printf("%lld ",ans[i]);
	printf("\n");

	return 0;
}