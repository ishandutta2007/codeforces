#include <stdio.h>

int ABS(int a)
{
	if(a<0) return -a;
	else return a;
}

int main()
{
	int a, b;
	scanf("%d %d",&a, &b);

	if(a==0 && b==0) printf("NO\n");
	else if(ABS(a-b)<=1) printf("YES\n");
	else printf("NO\n");

	return 0;
}