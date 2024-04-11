#include <bits/stdc++.h>
using namespace std;
int n, m, f[20];
bitset<19000001> b;
bitset<1000001> v;
long long z = 1;
int main()
{
	cin >> n >> m;
	for (int k = 1; k < 20; k++)
	{
		for (int j = 1; j <= m; j++)
		{
			b[k * j] = 1;
		}
		f[k] = b.count();
	}
	for (int i = 2; i <= n; i++)
	{
		if (v[i])
		{
			continue;
		}
		int c = 0;
		for (long long j = i; j <= n; j *= i)
		{
			v[j] = 1;
			c++;
		}
		z += f[c];
	}
	cout << z << endl;
	return 0;
}