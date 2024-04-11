#include <stdio.h>
const int N=1000050;
int a[N];
bool was[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	int cyc=0;
	for(i=1;i<=n;i++)
	{
		if(was[i]) continue;
		cyc++;
		for(j=i;!was[j];j=a[j]) was[j]=1;
	}
	if(cyc&1) printf("Um_nik\n");
	else printf("Petr\n");
	return 0;
}