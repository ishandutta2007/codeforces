#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
typedef long long ll;
int n, m, x;
ll y, z, ans, s[N];
void gao(int p, int k)
{
	for (int i = 0; i < k; i++)
	{
		y *= p;
	}
	for (int i = 0; i < (m - k) % m; i++)
	{
		z *= p;
		if (z > 100000)
		{
			z = 0;
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		y = z = 1;
		for (int i = 2; i * i <= x; i++)
		{
			if (x % i == 0)
			{
				int c = 0;
				while (x % i == 0)
				{
					c++;
					x /= i;
				}
				gao(i, c % m);
			}
		}
		if (x > 1)
		{
			gao(x, 1);
		}
		ans += s[z];
		s[y]++;
	}
	cout << ans << endl;
	return 0;
}