#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100005];
int b[100005];
int main()
{
	int n,l,r,i;
	scanf("%i%i%i",&n,&l,&r);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%i",&b[i]);
	}
	sort(a+l,a+r+1);
	sort(b+l,b+r+1);
	for(i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			printf("LIE\n");
			return 0;
		}
	}
	printf("TRUTH\n");
	return 0;
}