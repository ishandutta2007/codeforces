#include <stdio.h>
const int N=200005;
long long a[N],k,sol;
int n;
bool Check(long long x)
{
	int i;
	long double y=1,z=0;
	if(!x)
	{
		for(i=1;i<=n;i++) if(a[i]>=k) return true;
		return false;
	}
	if(x==1)
	{
		for(i=1;i<=n;i++) z+=a[i];
		return z>=k;
	}
	for (i=0;i<n;i++){
		if (i)
			y=y*(i+1+x-2);
		if (i>0)y/=i;
		if (y>k || y<0)y=k;
		if (y*a[n-i]<0)return true;
		z+=y*a[n-i];
		if (z<0 || z>=k)return true;
	}
	return false;
}
long long min(long long a, long long b)
{
	if(a>b) return b;
	else return a;
}
int main()
{
	int i;
	scanf("%i %lld",&n,&k);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	long long bot=0,top=k,mid;
	sol=k;
	while(top>=bot)
	{
		mid=(top+bot)>>1;
		if(Check(mid)) sol=min(mid,sol),top=mid-1;
		else bot=mid+1;
	}
	printf("%lld\n",sol);
	return 0;
}