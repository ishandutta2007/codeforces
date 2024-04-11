#include<stdio.h>
int main()
{
	int n, a, b;
	scanf("%d%d:%d", &n, &a, &b);
	if(b >= 60) b = b%10;
	if(n == 24)
	{
		if(a > 23) a = a%10;
	} else
	{
		if(a > 12 || a==0)
		{
			if(a%10 == 0) a = 10;
			else a = a%10;
		}
	}
	printf("%02d:%02d", a, b);
	return 0;
}