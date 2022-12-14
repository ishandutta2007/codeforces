#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
int a[N],n,I,p[N],sp,b[N];
int main()
{
	scanf("%d%d",&n,&I);I<<=3;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[i]=a[i];
	sort(p+1,p+n+1);sp=unique(p+1,p+n+1)-p-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(p+1,p+sp+1,a[i])-p,b[a[i]]++;
	for(int i=1;i<=sp;i++)b[i]+=b[i-1];
	int lim = 1 << min(I/n , 25) , ans = n-1;
	if(lim>sp) ans = 0;
	for(int i=1;i+lim-1<=sp;i++)ans=min(ans,n-b[i+lim-1]+b[i-1]);
	printf("%d\n",ans);
}