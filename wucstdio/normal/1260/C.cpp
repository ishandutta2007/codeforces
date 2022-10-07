#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,p1,p2,k;
int gcd(int a,int b)
{
	if(a==0)return b;
	return gcd(b%a,a);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&p1,&p2,&k);
		int d=__gcd(p1,p2);
		p1/=d,p2/=d;
		if(p1>p2)swap(p1,p2);
		if((p2-2)/p1+1<k)printf("OBEY\n");
		else printf("REBEL\n");
	}
	return 0;
}