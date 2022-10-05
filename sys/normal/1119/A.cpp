#include <bits/stdc++.h>
using namespace std;
int n,a[300005],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]==a[n]) continue;
		else ans=max(ans,n-i);
	for(int i=n;i>=1;i--)
		if(a[i]==a[1]) continue;
		else ans=max(ans,i-1);
	printf("%d",ans);
	return 0;
}