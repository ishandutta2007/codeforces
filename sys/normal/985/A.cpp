#include <bits/stdc++.h>
using namespace std;
int as,ans,n,num[105];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++)
		scanf("%d",&num[i]);
	sort(num+1,num+1+n/2);
	for(int i=1;i<=n/2;i++)
		ans+=abs(num[i]-2*i+1);
	for(int i=1;i<=n/2;i++)
		as+=abs(num[i]-2*i);
	printf("%d",min(as,ans));
	return 0;
}