#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

int main() {
	scanf("%lld",&n);
	if (n==0) return printf("0 0\n"), 0;
	ll level = (long long) sqrt(n/3);
	while (level*(level-1)*6/2>=n) level-=1;
	while (level*(level+1)*6/2<n) level+=1;
	n-=level*(level-1)*6/2;
	if (n<level) return printf("%lld %lld\n",2*level-n,2*n), 0;
	n-=level;
	if (n<level) return printf("%lld %lld\n",level-2*n,level*2), 0;
	n-=level;
	if (n<level) return printf("%lld %lld\n",-level-n,level*2-2*n), 0;
	n-=level;
	if (n<level) return printf("%lld %lld\n",-2*level+n,-2*n), 0;
	n-=level;
	if (n<level) return printf("%lld %lld\n",-level+2*n,-level*2), 0;
	n-=level;
	if (n<=level) return printf("%lld %lld\n",level+n,-level*2+2*n), 0;

	return 0;
}