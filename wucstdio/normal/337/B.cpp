#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int gcd(int a,int b)
{
	if(a==0)return b;
	if(a>b)return gcd(b,a);
	return gcd(b%a,a);
}
int a,b,c,d;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a*d==b*c)
	{
		printf("0/1\n");
		return 0;
	}
	if(a*d<b*c)
	{
		int x=b*c;
		int y=b*c-a*d;
		int d=gcd(x,y);
		x/=d;
		y/=d;
		printf("%d/%d\n",y,x);
	}
	else
	{
		int x=a*d;
		int y=a*d-b*c;
		int d=gcd(x,y);
		x/=d;
		y/=d;
		printf("%d/%d\n",y,x);
	}
	return 0;
}