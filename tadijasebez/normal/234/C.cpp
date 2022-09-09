#include <stdio.h>
const int N=100050;
int a[N],b[N],t[N];
int min(int a, int b){ return a>b?b:a;}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&t[i]),a[i]=a[i-1]+(t[i]>=0),b[i]=b[i-1]+(t[i]<=0);
	int sol=n;
	for(i=1;i<n;i++) sol=min(sol,a[i]+b[n]-b[i]);
	printf("%i\n",sol);
	return 0;
}