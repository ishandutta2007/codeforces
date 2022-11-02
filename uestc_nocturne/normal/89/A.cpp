#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef __int64 LL;
const int oo=1000000000;
int a[120000],n,m,k,i,mi,ans;
int main()
{
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		if(n%2==0){puts("0");continue;}
		mi=oo;
		for(i=1;i<=n;i+=2)
		mi=min(mi,a[i]);
		LL d=(LL)(n/2+1);
		LL x=(LL)(m/d);
		ans=(int)min(x*k,(LL)mi);
		printf("%d\n",ans);
	}
}