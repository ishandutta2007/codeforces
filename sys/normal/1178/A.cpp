#include <bits/stdc++.h>
using namespace std;
const int Maxn=105;
int ans,a[Maxn];
int n,sum; 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum+=a[i];
	int now=a[1];
	for(int i=2;i<=n;i++)
		if(a[i]*2<=a[1]) ans++,now+=a[i];
	if(now*2<=sum)
	{
		printf("0");
		return 0;
	}
	printf("%d\n1 ",ans+1);
	for(int i=2;i<=n;i++)
		if(a[i]*2<=a[1])
			printf("%d ",i);
	return 0;
}