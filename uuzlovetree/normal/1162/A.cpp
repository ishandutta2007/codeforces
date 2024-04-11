#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,h,m;
int a[105];
int main()
{
	scanf("%d%d%d",&n,&h,&m);
	for(int i=1;i<=n;++i)a[i]=h;
	for(int i=1;i<=m;++i)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		for(int p=l;p<=r;++p)a[p]=min(a[p],x);
	}
	int ans=0;
	for(int i=1;i<=n;++i)ans=ans+a[i]*a[i];
	printf("%d\n",ans);
	return 0;
}