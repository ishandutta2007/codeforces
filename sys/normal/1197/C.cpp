#include <bits/stdc++.h>
using namespace std;
const int Maxn=300005;
int n,k,a[Maxn],ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=a[n]-a[1];
	for(int i=1;i<n;i++)
		a[i]=a[i+1]-a[i];
	sort(a+1,a+n);
	reverse(a+1,a+n); 
	for(int i=1;i<k;i++)
		ans-=a[i];
	printf("%d",ans);
	return 0;
}