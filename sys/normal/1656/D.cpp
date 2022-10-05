#include <bits/stdc++.h>
using namespace std;

int T;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		long long n, tmp;
		scanf("%lld", &n), tmp = 1;
		while (n % 2 == 0) n /= 2, tmp <<= 1;
		if (n == 1) puts("-1");
		else printf("%lld\n", min(2 * tmp, n));	
	}
	return 0;
}