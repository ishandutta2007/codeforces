#include <cstdio>
#include <algorithm>

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int m, d, w;
		scanf("%d%d%d", &m, &d, &w);
		int t = std::min(m, d);
		if (d == 1) printf("0\n");
		else printf("%lld\n", (long long)t * (t / (w / std::__gcd(w, d - 1))) - (long long)(t / (w / std::__gcd(w, d - 1))) * (t / (w / std::__gcd(w, d - 1)) + 1) / 2 * (w / std::__gcd(w, d - 1)));
	}
	return 0;
}