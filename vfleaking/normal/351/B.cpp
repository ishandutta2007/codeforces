#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 3000;

int main()
{
	int n;
	static int p[MaxN + 1];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (p[i] > p[j])
				cnt++;

	double res;
	if (cnt % 2 == 0)
		res = cnt * 2;
	else
		res = cnt * 2 - 1;
	printf("%.7lf\n", res);

	return 0;
}