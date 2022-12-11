#include <bits/stdc++.h>
using namespace std;

map<long long, int> st;

int total(long long n)
{
	if (n <= 1) return n;
	else return n % 2 + 2 * total(n / 2);
}

int recur(long long n, long long l, long long r)
{
	if (l > r) return 0;

	long long total_len = 1;
	for (long long t = n; t > 1; t >>= 1, total_len = total_len * 2 + 1);

	if (l == 0 && r == total_len - 1) return total(n);

	if (r < total_len / 2)
	{
		return recur(n / 2, l, r);
	}
	else if (l > total_len / 2)
	{
		return recur(n / 2, l - total_len / 2 - 1, r - total_len / 2 - 1);
	}
	else
	{
		return n % 2 + recur(n / 2, l, total_len / 2 - 1) +
			recur(n / 2, 0, r - total_len / 2 - 1);
	}
}

int main()
{
	long long n, l, r;
	scanf("%lld%lld%lld", &n, &l, &r);
	l--; r--;
	printf("%d\n", recur(n, l, r));
}