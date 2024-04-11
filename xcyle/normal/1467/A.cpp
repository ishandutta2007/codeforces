#include <iostream>
#include <cstdio>
using namespace std;
int T, n;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		if(n == 1)
		{
			printf("9\n");
		}
		if(n == 2)
		{
			printf("98\n");
		}
		if(n > 2)
		{
			printf("98");
			int last = 9;
			for (int i = 3; i <= n; i++)
			{
				printf("%d",last);
				last = (last + 1) % 10;
			}
			printf("\n");
		}
	}
	return 0;
}