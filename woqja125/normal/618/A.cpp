#include<stdio.h>
void print(int x, int c)
{
	if(x==1)
	{
		printf("%d ", c);
		return;
	}
	print(x/2, c+1);
	if(x%2 == 1)printf("%d ", c);
}
int main()
{
	int n;
	scanf("%d", &n);
	print(n, 1);
	return 0;
}