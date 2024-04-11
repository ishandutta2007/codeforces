#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m,l,r;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&l,&m);
		r=l;
		while(m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(r>=x&&l<=y)l=min(l,x),r=max(r,y);
		}
		printf("%d\n",r-l+1);
	}
	return 0;
}