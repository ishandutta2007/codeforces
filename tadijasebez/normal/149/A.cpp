#include <stdio.h>
#include <algorithm>
using namespace std;
int a[15];
int main()
{
	int i,k;
	scanf("%i",&k);
	for(i=1;i<=12;i++) scanf("%i",&a[i]);
	sort(a+1,a+1+12);reverse(a+1,a+1+12);
	if(k==0) return printf("0\n"),0;
	int sum=0;for(i=1,sum+=a[1];i<=12;i++,sum+=a[i]) if(sum>=k) return printf("%i\n",i),0;
	printf("-1\n");
	return 0;
}