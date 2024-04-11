#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, a[100001];
bool not_prime[100001];
void init()
{
	for (int i = 2; i <= 100000; i++)
	{
		if (!not_prime[i])
		{
			for (int j = i + i; j <= 100000; j += i)
			{
				not_prime[j] = 1;
			}
		}
	}
}
int main()
{
	init();
	scanf("%d", &n);
	if (n == 1 || n == 2)
	{
		printf("-1");
		return 0;
	}
	int temp = n;
	for (; not_prime[temp]; temp++);
	printf("%d\n", temp);
	for (int i = 1; i <= n; i++)
	{
		printf("%d %d\n", i, i + 1 > n ? 1 : i + 1);
	}
	for (int i = 1; i <= temp - n; i++)
	{
		printf("%d %d\n", i, n - i);
	}
	return 0;
}