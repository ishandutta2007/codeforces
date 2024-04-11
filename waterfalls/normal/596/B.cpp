#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int main() {
	scanf("%d",&n);
	ll ans = 0;
	ll prev = 0;
	for (int i=0;i<n;i++) {
		ll b;
		scanf("%lld",&b);
		b-=prev;
		ans+=abs(b);
		prev = b+prev;
	}
	printf("%lld\n",ans);

	return 0;
}