#include <stdio.h>
#include <algorithm>
using namespace std;
int a[150];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	sort(a,a+n);
	for(i=0;i<n;i++) printf("%i ",a[i]);
	printf("\n");
	return 0;
}