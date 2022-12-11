#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int x,y;
	scanf("%d%d",&y,&x);
	int a[3]={x,x,x},ans=2;
	while (a[2]<y)
	{
		a[0]=a[1]+a[2]-1;
		sort(a,a+3);
		ans++;
	}
	printf("%d", ans);
}