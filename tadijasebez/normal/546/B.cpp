#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=10005;
int a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	sort(a+1,a+1+n);
	int sol=0;
	for(i=2;i<=n;i++) while(a[i]<=a[i-1]) a[i]++,sol++;
	printf("%i\n",sol);
	return 0;
}