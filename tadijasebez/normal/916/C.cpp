#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int mod=958989859;
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	printf("%i %i\n",mod,mod);
	for(i=1;i<n-1;i++)
	{
		printf("%i %i %i\n",i,i+1,1);
	}
	printf("%i %i %i\n",n-1,n,mod-n+2);
	int cnt=n;
	for(i=1;i<=n;i++)
	{
		if(cnt>m) break;
		for(j=i+2;j<=n;j++)
		{
			printf("%i %i %i\n",i,j,mod+69);
			cnt++;
			if(cnt>m) break;
		}
	}
	return 0;
}