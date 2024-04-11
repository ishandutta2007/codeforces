#include <stdio.h>
const int N=105;
int a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	int t=a[1]-a[0];
	bool ok=true;
	for(i=1;i<n;i++) if(a[i]-a[i-1]!=t) ok=false;
	if(ok) printf("%i\n",a[n-1]+t);
	else printf("%i\n",a[n-1]);
	return 0;
}