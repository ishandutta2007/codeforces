#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef unsigned u32;

const int MaxN = 100000;

int main()
{
	int n, k;
	static u32 a[MaxN];

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		u32 a1, a2, a3, a4;
		scanf("%u.%u.%u.%u", &a1, &a2, &a3, &a4);
		a[i] = a1 << 24 | a2 << 16 | a3 << 8 | a4;
	}

	for (int i = 1; i <= 31; i++)
	{
		u32 mask = ~0 << (32 - i);
		static u32 b[MaxN];
		for (int j = 0; j < n; j++)
			b[j] = a[j] & mask;
		sort(b, b + n);
		if (unique(b, b + n) - b == k)
		{
			printf("%u.%u.%u.%u\n", mask >> 24, mask >> 16 & 0xff, mask >> 8 & 0xff, mask & 0xff);
			return 0;
		}
	}

	cout << "-1" << endl;

	return 0;
}