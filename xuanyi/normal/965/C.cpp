#include <cstdio>
typedef unsigned long long ll ;

ll n, k, M, D , ans ;

template <typename T>
inline T max(const T &x, const T &y) {
	if (x < y) return y ;
	return x ;
}

ll ceil(double x) {
	ll t = x ;
	if (t < x) return t + 1 ;
	return t ;
}

int main() {
	scanf("%llu%llu%llu%llu", &n, &k, &M, &D) ;
	for (int d = 1 ; d <= D ; d++) {
		ll xd = n / ((d-1)*k+1) ;
		if (1.0*xd < 1.0 * (n+1) / (k*D+1)) break ;
		if (M < xd) xd = M ; 
//		ll nw = ((n-xd) / k + 1) * xd ;
		ll nw = xd * d ;
		ans = max(ans, nw) ;
	}
	printf("%llu\n", ans) ;
	return 0 ;
}