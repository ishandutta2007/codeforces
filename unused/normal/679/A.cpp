#include <stdio.h>
#include <string.h>

int primes[] = {
	2,      3 ,     5   ,   7   ,  11   ,  13   ,  17   ,  19    , 23   ,  29,
	31,     37 ,    41  ,   43  ,   47   ,  53   ,  59   ,  61   ,  67  ,   71,
	73 ,    79  ,   83  ,   89  ,   97 };

char str[1000];

int main()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", primes[i]);
		fflush(stdout);
		scanf("%s", str);
		if (strcmp(str, "yes") == 0) break;
	}
	if (i == 4)
	{
		printf("prime\n");
		fflush(stdout);
	}
	else
	{
		for (int j = i; primes[j] * primes[i] <= 100; j++)
		{
			printf("%d\n", primes[j] * primes[i]);
			fflush(stdout);
			scanf("%s", str);
			if (strcmp(str, "yes") == 0)
			{
				printf("composite\n");
				fflush(stdout);
				return 0;
			}
		}
		printf("prime\n");
		fflush(stdout);
	}	
}