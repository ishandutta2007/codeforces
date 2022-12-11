#include <bits/stdc++.h>
using namespace std;

bool notprime[100005];
void gp()
{
	notprime[1] = true;
	for (int i = 2; i <= 100001; i++)
	{
		if (notprime[i]) continue;
		for (int j = i * 2; j <= 100001; j += i)
			notprime[j] = true;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	gp();
	if (n == 1)
	{
		printf("1\n1\n");
		return 0;
	}

	if (n == 2)
	{
		printf("1\n1 1\n");
		return 0;
	}

	printf("2\n");

	for (int i = 2; i <= n + 1; i++)
	{
		if (notprime[i]) printf("1 ");
		else printf("2 ");
	}
	printf("\n");
}