#include <stdio.h>
const int N=150;
int a[N],b[N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=n;i>0;i--) b[i]=b[i+1]+a[i];
	int sol=b[1],t=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==0) t++;
		sol=max(sol,t+b[i+1]);
	}
	printf("%i\n",sol);
	return 0;
}