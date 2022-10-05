#include <bits/stdc++.h>
using namespace std;
int n,k;
long long a[200005];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	sort(a+1,a+1+n);
	if(k==0) {if(a[1]==1)printf("-1"); else printf("1"); return 0;}
	if(a[k]==a[k+1]) printf("-1");
	else printf("%I64d",a[k]);
	return 0;
}