#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,y,maxx;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		maxx=max(maxx,x+y);
	}
	printf("%d\n",maxx);
	return 0;
}