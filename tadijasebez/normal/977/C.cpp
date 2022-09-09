#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=200050;
int a[N];
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	a[0]=1;
	sort(a+1,a+1+n);
	if(a[k]==a[k+1]) return printf("-1\n"),0;
	printf("%i\n",a[k]);
	return 0;
}