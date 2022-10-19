#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],b[N];
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1],b[i]+=b[i-1];
	int ans=INT_MAX;
	for(int i=1;i<=n;i++)
		ans=min(ans,max(b[i-1],a[n]-a[i]));
	printf("%d\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}