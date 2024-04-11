#include <cstdio>
#include <algorithm>

int main()
{
	int a[3];
	for(int i=0;i<3;i++)
		scanf("%i",a+i);
	std::sort(a,a+3);
	printf("%i\n", (a[2]-a[0]));
}