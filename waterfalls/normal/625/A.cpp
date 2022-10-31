#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,a,b,c;

int main() {
	scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
	if (a<b-c || n<b) return printf("%lld\n",n/a), 0;
	ll num = (n-c)/(b-c);
	printf("%lld\n",num+(n-num*(b-c))/a);

	return 0;
}