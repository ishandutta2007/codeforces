#include <stdio.h>
int gcd(int x, int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
const int N=2050;
const int inf=1e9+7;
int a[N];
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	int one=0;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]==1) one++;
	}
	if(one) return printf("%i\n",n-one),0;
	int sol=inf;
	for(i=1;i<=n;i++)
	{
		j=i+1;
		int tmp=a[i];
		while(j<=n && tmp!=1) tmp=gcd(tmp,a[j]),j++;
		if(tmp==1) sol=min(sol,j-i-1);
	}
	if(sol==inf) printf("-1\n");
	else printf("%i\n",n-1+sol);
	return 0;
}