#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n;
long long x, y, z;
int l[100020];
int r[100020];
stack<int> s;
int main()
{
	scanf("%d%lld%lld", &n, &x, &y);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		z = (z + (r[i] - l[i]) * y) % mod;
	}
	sort(l, l + n);
	sort(r, r + n);
	for (int i = 0, j = 0; i < n; i++)
	{
		for (; j < n && r[j] < l[i]; j++)
		{
			s.push(r[j]);
		}
		if (s.size() > 0 && (l[i] - s.top()) * y < x)
		{
			z = (z + (l[i] - s.top()) * y) % mod;
			s.pop();
		}
		else
		{
			z = (z + x) % mod;
		}
	}
	printf("%lld\n", z);
	return 0;
}