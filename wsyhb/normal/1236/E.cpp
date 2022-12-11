#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],l[max_n<<1],r[max_n<<1];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=m;++i)
		scanf("%d",a+i);
	for(int i=0;i<=m+n+1;++i)
	{
		l[i]=max(i-m-1,1);
		r[i]=min(i+1,n);
	}
	for(int i=m;i>=1;--i)
	{
		r[a[i]-i+m]=r[a[i]-i-1+m];
		l[a[i]+i]=l[a[i]+i+1];
	}
	long long ans=0;
	for(int i=1;i<=n;++i)
		ans+=r[i+m]-l[i]+1;
	printf("%lld\n",ans);
	return 0;
}