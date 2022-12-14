#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;
#define N 200005
int a[N],n,s;long long ans;
int main()
{
	scanf("%d%d",&n,&s);for(int i=1;i<=n;i++)scanf("%d",&a[i]);sort(a+1,a+n+1);
	int m=(n+1)>>1;
	if(s>a[n])
	{
		for(int i=m;i<=n;i++)ans+=abs((long long)s-a[i]);
		printf("%lld\n",ans);return 0;
	}
	if(s<a[1])
	{
		for(int i=1;i<=m;i++)ans+=abs((long long)s-a[i]);
		printf("%lld\n",ans);return 0;
	}
	int p=lower_bound(a+1,a+n+1,s)-a;
	if(p==m){printf("%lld\n",(long long)a[m]-s);return 0;}
	else if(p>m)
	{
		for(int i=m;i<p;i++)ans+=abs((long long)s-a[i]);
		printf("%lld\n",ans);
	}else 
	{
		for(int i=p;i<=m;i++)ans+=abs((long long)a[i]-s);
		printf("%lld\n",ans);
	}return 0;
}