#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		char input[100];
		scanf(" IAO'%s", input);
		int len = strlen(input);

		long long start = 1988;
		long long radix = 1;

		for (int i = len - 1; i >= 0; i--)
		{
			int target = atoi(input + i);

			do start += radix; 
			while (start % (radix * 10) != target);

			radix *= 10;
		}

		printf("%lld\n", start);
	}
}