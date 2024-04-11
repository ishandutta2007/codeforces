#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a,x,b,y;
int main()
{
	scanf("%d%d%d%d%d",&n,&a,&x,&b,&y);
	if(a==b)
	{
		printf("YES\n");
		return 0;
	}
	while(a!=x&&b!=y)
	{
		a=a%n+1;
		b=(b-2+n)%n+1;
		if(a==b)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}