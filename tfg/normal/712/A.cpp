#include <cstdio>

int a[100100];
int b[100100];

int main()
{
	int n, temp=0;
	scanf("%i",&n);
	for(int i=0;i<n;i++) scanf("%i",&a[i]);
	b[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--) b[i]=a[i+1]+a[i];
	for(int i=0;i<n;i++) printf("%i ",b[i]);
	return 0;
}