#include <bits/stdc++.h>
using namespace std;
const int Maxn=400005;
int n,I,a[Maxn],cnt[Maxn],b[Maxn],ans,ct,sum[2*Maxn];
int main()
{
	scanf("%d%d",&n,&I);
	I*=8;
	I/=n;
	I=min(I,30);
	I=1<<I;
        if(I>=n) return puts("0"),0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i-1]) sum[++ct]=i;
        sum[++ct]=n;
        if(ct<=I) return puts("0"),0;
	for(int i=0;i<=ct;i++)
		ans=max(ans,sum[i+I]-sum[i]); 
	printf("%d",n-ans);
	return 0;
}