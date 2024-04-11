#include<stdio.h>
#include<algorithm>
using namespace std;
int a[2],n,z;
int main()
{
	scanf("%d%d%d",a,a+1,&n);
	while(n-=__gcd(a[z],n))
		z^=1;
	printf("%d\n",z);
}