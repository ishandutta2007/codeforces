#include <stdio.h>
int main()
{
	int n,x;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i",&x);
		while(1)
		{
			if(x%3==0){ printf("YES\n");break;}
			x-=7;
			if(x<0){ printf("NO\n");break;}
		}
	}
	return 0;
}