#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long a[N],s[N],pre[N];
int main()
{
	int n,i,m;
	long long l,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<n;i++)
		s[i]=a[i+1]-a[i];
	sort(s+1,s+n);
	for(i=1;i<n;i++)
		pre[i]=pre[i-1]+s[i];
	scanf("%d",&m);
	while(m--)
	{
		scanf("%I64d %I64d",&l,&r);
		int z=lower_bound(s+1,s+n,r-l+1)-s-1;
		printf("%I64d\n",(1ll*n-z)*(r-l+1)+pre[z]);
	}
	return 0;
}