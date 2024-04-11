#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c,x,y,z,sum;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if(a+b+c&1)
	{
		printf("Impossible\n");
		return 0;
	}
	sum=a+b+c>>1;
	x=sum-c;
	y=sum-a;
	z=sum-b;
	if(x<0||y<0||z<0)
	{
		printf("Impossible\n");
		return 0;
	}
	printf("%d %d %d\n",x,y,z);
	return 0;
}