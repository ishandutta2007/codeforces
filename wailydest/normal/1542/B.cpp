#include <cstdio>

int t, n, a, b;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &a, &b);
		bool ok;
		if (a == 1) ok = !((n - 1) % b);
		else {
			ok = false;
			long long k = 1;
			for (k = 1; k <= n; k *= a) if (!((n - k) % b)) ok = true;
		}
		if (ok) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}