#include <bits/stdc++.h>
using namespace std;

long long n, ans, tmp, cnt;
int main()
{
	scanf("%lld", &n);
	tmp = n;
	int maxi = sqrt(n);
	for (int i = 2; i <= maxi; i++)
		if (n % i == 0)
		{
			cnt++;
			tmp = i;
			while (n % i == 0) n /= i;
		}
	if (n != 1) cnt++;
	if (cnt > 1)
		printf("1");
	else if (cnt) printf("%lld", tmp);
	else printf("%lld", n);
	return 0;
}