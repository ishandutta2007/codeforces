#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MaxN = 2000;

int main()
{
	int n;
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j < i; j++)
			if (abs(a[j]) < abs(a[i]))
				cnt++;
		for (int j = i + 1; j <= n; j++)
			if (abs(a[j]) < abs(a[i]))
				cnt--;
		if (cnt > 0)
			a[i] = abs(a[i]);
		else
			a[i] = -abs(a[i]);
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i] > a[j])
				res++;
	cout << res << endl;

	return 0;
}