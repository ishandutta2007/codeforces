#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[1007];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=2;i<n;i++)
	{
		if (a[i]>a[i-1]&&a[i]>a[i+1]) ++ans;
		if (a[i]<a[i-1]&&a[i]<a[i+1]) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}