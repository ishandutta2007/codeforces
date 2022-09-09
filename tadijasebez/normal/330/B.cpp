#include <stdio.h>
const int N=1050;
bool bad[N];
int main()
{
	int n,r,m,u,v,i;
	scanf("%i %i",&n,&m);
	while(m--) scanf("%i %i",&u,&v),bad[u]=1,bad[v]=1;
	for(i=1;i<=n;i++) if(!bad[i]) r=i;
	printf("%i\n",n-1);
	for(i=1;i<=n;i++)
	{
		if(i==r) continue;
		printf("%i %i\n",i,r);
	}
	return 0;
}