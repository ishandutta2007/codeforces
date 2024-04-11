#include <stdio.h>
const int N=200050;
int Last[N],Min;
bool vis[N];
int main()
{
	int n,x,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&Last[i]);
	for(i=n;i>0;i--) if(!vis[Last[i]])
	{
		Min=Last[i];
		vis[Last[i]]=1;
	}
	printf("%i\n",Min);
	return 0;
}