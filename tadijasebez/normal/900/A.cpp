#include <stdio.h>
int C[2];
int main()
{
	int n,x,y,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&x,&y);
		C[x<0]++;
	}
	if(C[0]<2 || C[1]<2) printf("Yes\n");
	else printf("No\n");
	return 0;
}