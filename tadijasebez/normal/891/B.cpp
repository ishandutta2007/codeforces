#include <stdio.h>
#include <algorithm>
using namespace std;
pair<int,int> a[25];
int b[25];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i].first),a[i].second=i;
	sort(a+1,a+1+n);
	for(i=1;i<n;i++) b[a[i].second]=a[i+1].first;
	b[a[n].second]=a[1].first;
	for(i=1;i<=n;i++) printf("%i ",b[i]);
	printf("\n");
	return 0;
}