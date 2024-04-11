#include <bits/stdc++.h>
using namespace std;
int b,k,a[100005],ans,now=1;
int main()
{
	scanf("%d%d",&b,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	for(int i=k;i>=1;i--)
	{
		ans=(ans+a[i]*now)%2;
		now=(now*b)%2;
	}
	if(ans) printf("odd");
	else printf("even");
	return 0;
}