#include <stdio.h>
int main()
{
	int l,r,x,y,k,i;
	scanf("%i %i %i %i %i",&l,&r,&x,&y,&k);
	for(i=l;i<=r;i++)
	{
		if(i%k==0 && i/k>=x && i/k<=y)
		{
			//printf("%i\n",i);
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}