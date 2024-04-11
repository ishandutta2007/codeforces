#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 100000;
const int MaxA = 100000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n;
	static int a[MaxN + 1];
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	static int f[MaxA + 1];
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		static vector<int> factor;
		factor.clear();
		for (int j = 2; j * j <= a[i]; j++)
			if (a[i] % j == 0)
			{
				factor.push_back(j);
				while (a[i] % j == 0)
					a[i] /= j;
			}
		if (a[i] > 1)
			factor.push_back(a[i]);

		int val = 0;
		for (vector<int>::iterator j = factor.begin(); j != factor.end(); j++)
			relax(val, f[*j]);
		val++;

		relax(res, val);
		for (vector<int>::iterator j = factor.begin(); j != factor.end(); j++)
			f[*j] = val;
	}

	cout << res << endl;

	return 0;
}