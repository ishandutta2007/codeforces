#include <stdio.h>
#include <cstring>
char a[100050];
int sol[100050];
int u[100050];
int main()
{
	int q,l,r,i,n;
	scanf("%s",&a);
	n=(unsigned) strlen(a);
	for(i=0;i<n-1;i++)
	{
		if(a[i]==a[i+1]) u[i]=1;
	}
	for(i=1;i<=n;i++) sol[i]=sol[i-1]+u[i-1];
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&l,&r);
		printf("%i\n",sol[r-1]-sol[l-1]);
	}
	return 0;
}