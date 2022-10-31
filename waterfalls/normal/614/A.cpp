#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll l,r,k;
const ll INF = 8e18;

int main() {
	scanf("%lld%lld%lld",&l,&r,&k);
	int ans = 0;
	ll cur = 1;
	while (true) {
		if (l<=cur && cur<=r) {
			printf("%lld ",cur);
			ans+=1;
		}
		if (INF/k<cur) break;
		cur*=k;
	}
	if (!ans) printf("-1");
	printf("\n");

	return 0;
}