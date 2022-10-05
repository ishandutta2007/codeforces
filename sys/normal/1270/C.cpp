#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, a[Maxn], n;
long long Xor, sum;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		sum = Xor = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), sum += a[i], Xor ^= a[i];
		sum += Xor;
		printf("2\n%lld %lld\n", Xor, sum);
	}
	return 0;
}