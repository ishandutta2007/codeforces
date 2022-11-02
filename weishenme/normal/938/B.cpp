#include<bits/stdc++.h>
using namespace std;
int a[200005],n,ans=1e9;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[0]=1;a[n+1]=1e6;
	for (int i=0;i<=n;i++)
	 ans=min(ans,max(a[i]-1,1000000-a[i+1]));
	printf("%d\n",ans); 
}