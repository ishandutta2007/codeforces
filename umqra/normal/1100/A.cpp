#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200;
int type[N];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &type[i]);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int exam = 0, social = 0;
		for (int s = 0; s < n; s++)
		{
			if (s % k != i % k)
			{
				if (type[s] == 1)
					exam++;
				else
					social++;
			}
		}
		ans = max(ans, abs(exam - social));
	}
	printf("%d\n", ans);
	return 0;
}