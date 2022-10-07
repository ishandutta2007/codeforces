#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int l1,r1,l2,r2,x,y;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		x=l1,y=l2;
		if(x==y)x=r1;
		printf("%d %d\n",x,y);
	}
	return 0;
}