#include <stdio.h>
int a[1000050];
int main()
{
	int n,i;
	bool ok=false;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]%2==1) ok=true;
	}
	if(ok) printf("First\n");
	else printf("Second\n");
	return 0;
}