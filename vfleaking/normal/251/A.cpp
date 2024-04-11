#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

int main()
{
	int n, d;
	static int x[MaxN];
	
	cin >> n >> d;
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	
	s64 res = 0ll;
	for (int i = 0, j = 0; i < n; i++)
	{
		while (j < n && x[j] - x[i] <= d)
			j++;
		int t = j - i - 1;
		if (t >= 2)
			res += (s64)t * (t - 1) / 2;
	}
	cout << res << endl;
	
	return 0;
}