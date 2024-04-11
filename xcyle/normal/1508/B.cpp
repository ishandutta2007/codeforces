#include <iostream>
#include <cstdio>
#define maxn 100005
using namespace std;
int T, n;
long long k;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%lld", &n, &k);
		if(n <= 60 && k > (1ll << (n - 1)))
		{
			printf("-1\n");
			continue;
		}
		int j = 1;
		if(n > 61)
		{
			for (int j = 1; j <= n - 61; j++) printf("%d ", j);
			j = n - 60;
		}
		while(j <= n)
		{
			for (int i = 1; i <= n - j + 1; i++)
			{
//				printf("\n! %d %d %d\n", j, i, k);
				if(i == n - j + 1 || k <= (1ll << (n - j - i)))
				{
					int num = j + i - 1;
					for (int c = j; c <= j + i - 1; c++)
					{
						printf("%d ", num);
						num--;
					}
					j += i;
					break;
				} 
				else k -= (1ll << (n - j - i));
			}
		}
		printf("\n");
	}
	return 0;
}