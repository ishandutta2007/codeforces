#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,a[N];
long long t=1e18;
void chk(int x)
{
	if(!x)
		return;
	long long s=0;
	for(int i=1;i<=n;i++)
	{
		int f=(a[i]+x)/(x+1),g=f*(x+1)-a[i];
		if(f<g)
			return;
		s+=f;
	}
	t=min(t,s);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i*i<=a[1];i++)
	{
		chk(i);
		chk(a[1]/i);
		chk(a[1]/i-1);
	}
	printf("%lld\n",t);
	return 0;
}