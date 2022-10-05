#include <bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005];
long long ans,sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=a[i];
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+1+n);
	sum=b[n]+b[n-1];
	if(ans>sum) printf("NO");
	else printf("YES");
	return 0;
}