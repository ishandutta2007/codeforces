#include <bits/stdc++.h>
using namespace std;

int now = -1e8, ct1, ct2, ans1[20005], ans2[20005];
int query(int x, int y)
{
	printf("0 %d %d\n", x, y);
	fflush(stdout);
	int result;
	scanf("%d", &result);
	return result;
}
int Rand()
{
	return (rand() * RAND_MAX + rand()) % 200000001;
}
int main()
{
	srand(time(NULL));
	while (now <= 1e8)
	{
		int r = query(now, now);
		if (r) now += r;
		else
		{
			if (!query(now, Rand() - 1e8) && !query(now, Rand() - 1e8))
				ans1[++ct1] = now;
			if (!query(Rand() - 1e8, now) && !query(Rand() - 1e8, now))
				ans2[++ct2] = now;
			if (now == 1e8) break;
			int tmp = min(100000000, now + 100);
			if (query(tmp, tmp) == tmp - now) now = tmp;
			else now++;
		}
	}
	printf("1 %d %d\n", ct1, ct2);
	for (int i = 1; i <= ct1; i++)
		printf("%d ", ans1[i]);
	puts("");
	for (int i = 1; i <= ct2; i++)
		printf("%d ", ans2[i]);
	puts("");
	fflush(stdout);
	return 0;
}