#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

int main() {
	scanf("%lld",&n);
	ll i = 0;
	while ((i+1)*(i+2)/2<n) i+=1;
	printf("%lld\n",n-i*(i+1)/2);

	return 0;
}