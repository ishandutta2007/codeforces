#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
ll a[N],b[N];
int x[N];
int main()
{
	int n,i,j,k;ll t;
	scanf("%i %lld",&n,&t);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=1;i<=n;i++) scanf("%i",&x[i]);
    for(i=1;i<n;i++) if(x[i]>x[i+1]) return 0*printf("No\n");
    for(i=n;i>=1;i--)
	{
		if(x[i]!=i) return 0*printf("No\n");
		for(j=i;x[i]==x[j];j--);j++;
		for(k=j;k<i;k++) b[k]=a[k+1]+t;
		if(j==i) b[i]=a[i]+t;
		else b[i]=a[i]+t+1;
		if(i<n && b[i]>=a[i+1]+t) return 0*printf("No\n");
		i=j;
	}
	printf("Yes\n");
	for(i=1;i<=n;i++) printf("%lld ",b[i]);
	printf("\n");
	return 0;
}