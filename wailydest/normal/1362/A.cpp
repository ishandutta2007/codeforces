#include <cstdio>
#include <cmath>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		int x = __builtin_ctzll(a);
		int y = __builtin_ctzll(b);
		if ((a >> x) != (b >> y)) printf("-1\n");
		else {
			int k = abs(x - y);
			printf("%d\n", k / 3 + (k % 3) / 2 + (k % 3) % 2);
		}
	}
	return 0;
}