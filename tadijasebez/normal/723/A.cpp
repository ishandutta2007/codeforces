#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int a[3];
	scanf("%i%i%i",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	printf("%i",a[2]-a[0]);
	return 0;
}