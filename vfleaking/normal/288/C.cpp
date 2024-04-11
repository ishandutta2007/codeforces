#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 1000000;

int main()
{
	int n;
	s64 res = 0;
	cin >> n;

	static int p[MaxN + 1];
	for (int i = 0; i <= n; i++)
		p[i] = -1;
	
	int all = 1;
	while (all <= n)
		all <<= 1;
	while (all >= 1)
	{
		for (int i = 0; i <= n; i++)
		{
			int t = i ^ (all - 1);
			if (p[i] == -1 && t <= n && p[t] == -1)
			{
				p[i] = i ^ (all - 1), p[t] = i;
				res += 2 * (all - 1);
			}
		}
		all >>= 1;
	}

	cout << res << endl;
	for (int i = 0; i <= n; i++)
		printf("%d ", p[i]);
	cout << endl;

	return 0;
}