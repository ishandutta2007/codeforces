#include <stdio.h>
const int N=100050;
int p[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&p[i]);
	for(i=1;i<=n;i++)
	{
		if(p[p[i]]!=i && p[p[p[i]]]==i) return printf("YES\n"),0;
	}
	printf("NO\n");
	return 0;
}