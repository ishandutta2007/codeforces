#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=100050;
int a[N],id[N];
bool comp(int i, int j){ return a[i]<a[j];}
int main()
{
	int n,k,i,j;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id[i]=i;
	sort(id+1,id+1+n,comp);
	for(i=1;i<=n;i++) a[id[i]]+=a[id[i-1]];
	for(i=1;i<=n;i++)
	{
		if(a[id[i]]>k)
		{
			printf("%i\n",i-1);
			for(j=1;j<i;j++) printf("%i ",id[j]);
			printf("\n");
			return 0;
		}
	}
	printf("%i\n",n);
	for(i=1;i<=n;i++) printf("%i ",i);
	printf("\n");
	return 0;
}