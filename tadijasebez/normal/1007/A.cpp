#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100050;
int a[N];
int main()
{
	int n,i,j=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		if(a[i]>a[j+1]) j++;
	}
	printf("%i\n",j);
	return 0;
}