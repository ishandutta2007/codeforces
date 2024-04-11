#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long lli;

lli k,d,t;
int main() {
	scanf("%lld%lld%lld",&k,&d,&t);
	lli a = ((k-1) / d + 1) * d - k;
	lli lo=0,up=1e18;
	while(up-lo>1) {
		lli md = lo+up >> 1;
		if(md > 2*t / (2*k + a) || md * (2*k + a) > 2*t) {
			up=md;
		}
		else lo=md;
	}
	
	lli b = lo;

	double ans = lo * (a+k);
	ans += min(1.0*k, 1.0 * (2*t - b*(2*k+a))/2);
	ans += max(0ll, 2*t - b*(2*k + a) - 2*k);
	printf("%.10lf\n",ans);
	return 0;
}