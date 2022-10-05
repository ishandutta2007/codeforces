#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n;
long long a[Maxn],b[Maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++)
		scanf("%lld",&b[i]);
	a[n+1]=0x7fffffffffffffff;
	a[1]=0;
	a[n]=b[1];
	for(int i=2;i<=n/2;i++)
		a[i]=max(b[i]-a[n-i+2],a[i-1]),a[n-i+1]=b[i]-a[i];
	for(int i=1;i<=n;i++)
		printf("%lld ",a[i]);
	return 0;
}