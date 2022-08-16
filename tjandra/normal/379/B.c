#include<stdio.h>
typedef unsigned u;
int main()
{
	u n,i;
	scanf("%u%u",&n,&i);
	while(i--)printf("PRL");
	while(--n)
	{
		scanf("%u",&i);
		putchar('R');
		while(i--)printf("PLR");
	}
	putchar('\n');
	return 0;
}