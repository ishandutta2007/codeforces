#include <stdio.h>
int n,h,i,cnt;
int main()
{
	scanf("%d",&n);
	while (cnt <= n)
	{
		h++;
		cnt += (h*(h+1))/2;
	}
	printf("%d\n",h-1);
	return 0;
}