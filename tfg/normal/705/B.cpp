#include <cstdio>

int n;

int main()
{
	scanf("%i", &n);
	int parity=0;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%i", &temp);
		parity=(parity+temp-1)%2;
		if(parity) printf("1\n");
		else printf("2\n");
	}
}