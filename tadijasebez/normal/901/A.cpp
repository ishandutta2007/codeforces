#include <stdio.h>
const int N=200050;
int a[N],p[N];
int main()
{
	int n=0,m,i,taj=0;
	bool perfect=1;
	scanf("%i",&m);
	m++;
	for(i=1;i<=m;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]>1 && a[i-1]>1) perfect=0,taj=i;
		n+=a[i];
	}
	if(perfect || a[1]>1) return printf("perfect\n"),0;
	printf("ambiguous\n");
	int prev=0,mess=0,j=1;
	for(i=1;i<=n;i++)
	{
		printf("%i ",prev);
		//printf("%i %i\n",j,mess);
		if(i==mess+a[j]) mess+=a[j++],prev=i;
	}
	printf("\n");
	j=1;prev=0;mess=0;
	for(i=1;i<=n;i++)
	{
		if(j==taj && i==mess+a[j]) printf("%i ",prev-1);
		else printf("%i ",prev);
		if(i==mess+a[j]) mess+=a[j++],prev=i;
	}
	printf("\n");
	return 0;
}