#include <bits/stdc++.h>
using namespace std;
const int Maxn=105;
int n,a[Maxn],ans[Maxn],cnt;
int main() 
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) 
		if(i&1)
			ans[++cnt]=a[i];
		else 
			ans[n-cnt+1]=a[i];
	for(int i=1;i<=n;i++) 
		printf("%d ",ans[i]);
	return 0;
}