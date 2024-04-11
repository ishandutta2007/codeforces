#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 10;

int main()
{
	int n;
	static int a[1 << (MaxN + 1)];
	
	cin >> n;
	for (int i = 2; i < (1 << (n + 1)); i++)
	{
		scanf("%d", &a[i]);
		a[i] += a[i >> 1];
	}

	static int vm[1 << (MaxN + 1)];

	for (int i = (1 << n); i < (1 << (n + 1)); i++)
		vm[i] = a[i];
	for (int i = (1 << n) - 1; i >= 1; i--)
		vm[i] = max(vm[i << 1 | 0], vm[i << 1 | 1]);

	int res = 0;
	for (int i = 1; i < (1 << n); i++)
		res += abs(vm[i << 1 | 0] - vm[i << 1 | 1]);

	cout << res << endl;

	return 0;
}