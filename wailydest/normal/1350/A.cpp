#include <cstdio>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int md = n;
		for (int i = 2; i * i <= n && md == n; ++i) if (!(n % i)) md = i;
		if (md == 2) printf("%d\n", n + 2 * k);
		else printf("%d\n", n + md + 2 * (k - 1));
	}
	return 0;
}