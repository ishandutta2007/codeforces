#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	scanf("%lld",&n);
	n+=2*(1000000000000000000LL)/360*360;
	n%=360;
	long long best = min(n,360-n);
	int which = 0;
	for (int i=1;i<4;i++) {
		long long cur = (n+270*i)%360;
		if (min(cur,360-cur)<best) {
			best = min(cur,360-cur);
			which = i;
		}
	}
	printf("%d\n",which);

	return 0;
}