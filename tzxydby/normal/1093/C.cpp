#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N],b[N];
int main()
{
	int n;
	scanf("%d",&n);
	n/=2;
	for(int i=1;i<=n;i++)
		scanf("%I64d",&b[i]);
	a[1]=0;
	a[n*2]=b[1];
	for(int i=2;i<=n;i++)
	{
		a[i]=max(a[i-1],b[i]-a[n*2-i+2]);
		a[n*2-i+1]=b[i]-a[i];
	}
	for(int i=1;i<=n*2;i++)
		printf("%I64d ",a[i]);
	printf("\n");
	return 0;
}