#include <bits/stdc++.h>
using namespace std;
const int Maxn=2000005;
int n,a[Maxn];
int main()
{
	scanf("%d",&n);
	long long sum=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum+=a[i];
	sort(a+1,a+1+n); 
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int b;
		scanf("%d",&b);
		printf("%lld\n",sum-a[n-b+1]);
	}
	return 0;
}