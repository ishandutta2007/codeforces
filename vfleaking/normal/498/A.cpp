#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int res = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (((s64)a * x1 + (s64)b * y1 + c > 0) != ((s64)a * x2 + (s64)b * y2 + c > 0))
			res++;
	}

	cout << res << endl;

	return 0;
}