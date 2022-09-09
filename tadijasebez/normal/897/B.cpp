#include <stdio.h>
#define ll long long
ll sol;
int d[10];
ll BuildNumber(int n)
{
	int tmp=n,cnt=0;
	while(tmp>0) tmp/=10,cnt++;
	ll ret=(ll)n*d[cnt+1];
	//printf("%lld\n",ret);
	while(n>0)
	{
		int cif=n%10;
		ret+=cif*d[cnt];
		cnt--;
		n/=10;
	}
	return ret;
}
int main()
{
	int n,p,i;
	scanf("%i %i",&n,&p);
	d[1]=1;
	d[2]=10;
	d[3]=100;
	d[4]=1000;
	d[5]=10000;
	d[6]=100000;
	d[7]=1000000;
	for(i=1;i<=n;i++)
	{
		ll num=BuildNumber(i);
		sol=(sol+num)%p;
	}
	printf("%lld\n",sol);
	return 0;
}