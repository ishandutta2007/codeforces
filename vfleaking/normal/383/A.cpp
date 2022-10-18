#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 200000;

int main()
{
	int n;
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	long long res = 0;

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0)
			res += cnt;
		else
			cnt++;
	}

	cout << res << endl;

	return 0;
}