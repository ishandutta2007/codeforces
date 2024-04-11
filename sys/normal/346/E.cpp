#include <bits/stdc++.h>
using namespace std;

int T;
int work(int a, int n, int p)
{
	long long tmp_a = p % a, tmp_n = (n - p / a + 1) * (long long) a / p;
	if (a * (long long) n <= p - 1) return a;
	if (tmp_a * (long long) tmp_n <= (a - 1)) return max(tmp_a, a - tmp_n * tmp_a);
	return work(tmp_a, tmp_n, a);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int a, n, p, d;
		scanf("%d%d%d%d", &a, &n, &p, &d);
		puts(work(a % p, n, p) <= d ? "YES" : "NO");
	}
	return 0;
}