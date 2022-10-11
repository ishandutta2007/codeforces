#include <iostream>
#include <cstdio>

int n;

int freq[100100];

int main()
{
	std::cin >> n;
	int on=n;
	int i;
	for(i=0;i<n;i++)
	{
		int temp;
		scanf("%i", &temp);
		freq[temp]++;
		int got=0;
		while(freq[on])
		{
			if(got)
				printf(" ");
			printf("%i", on);
			on--;
			got++;
		}
		printf("\n");
	}
}