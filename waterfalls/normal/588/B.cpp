#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

int main() {
	scanf("%lld",&n);
	ll res = 1;
	for (ll i=2;i*i<=n;i++) if (n%i==0) {
		res*=i;
		while (n%i==0) n/=i;
	}
	res*=n;
	printf("%lld\n",res);

	return 0;
}