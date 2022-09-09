#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=100050;
int a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	sort(a+1,a+1+n);reverse(a+1,a+1+n);
	for(i=1;i<=n;i++) a[i]+=a[i-1];
	for(i=1;i<=n;i++) if(a[i]*2>a[n]) return printf("%i\n",i),0;
	return 0;
}