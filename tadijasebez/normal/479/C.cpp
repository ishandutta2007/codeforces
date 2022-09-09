#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=100050;
int a[N],b[N],id[N];
int max(int a, int b){ return a>b?a:b;}
bool comp(int i, int j){ return (a[i]==a[j] && b[i]<b[j]) || a[i]<a[j];}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i %i",&a[i],&b[i]),id[i]=i;
	sort(id+1,id+1+n,comp);
	int sol=b[id[1]];
	for(i=2;i<=n;i++)
	{
		if(b[id[i]]>=sol) sol=b[id[i]];
		else sol=a[id[i]];
	}
	printf("%i\n",sol);
	return 0;
}