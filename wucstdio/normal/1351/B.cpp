#include<cstdio>
#include<algorithm>
using namespace std;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int x,y,a,b;
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if(x>y)swap(x,y);
		if(a>b)swap(a,b);
		if(y==b&&x+a==y)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}