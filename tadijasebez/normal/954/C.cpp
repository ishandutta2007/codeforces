#include <stdio.h>
int abs(int x){ return x>0?x:-x;}
const int N=200050;
int a[N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,y=1,x=1000000000;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<n;i++) y=max(y,abs(a[i]-a[i+1]));
	for(i=1;i<n;i++)
	{
		if(abs(a[i]-a[i+1])!=y && abs(a[i]-a[i+1])!=1) return printf("NO\n"),0;
		if(abs(a[i]-a[i+1])!=y)
		{
			if(a[i]%y==1 && a[i+1]<a[i]) return printf("NO\n"),0;
			if(a[i]%y==0 && a[i]<a[i+1]) return printf("NO\n"),0;
		}
	}
	printf("YES\n");
	printf("%i %i\n",x,y);
	return 0;
}