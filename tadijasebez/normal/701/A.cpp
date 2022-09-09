#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=100050;
int a[N],id[N];
bool comp(int i, int j){ return a[i]<a[j];}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id[i]=i;
	sort(id+1,id+1+n,comp);
	for(i=1;i<=n/2;i++) printf("%i %i\n",id[i],id[n-i+1]);
	return 0;
}