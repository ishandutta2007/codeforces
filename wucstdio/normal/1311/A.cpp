#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(n==m)printf("0\n");
		else if(n<m)
		{
			if((m-n)&1)printf("1\n");
			else printf("2\n");
		}
		else
		{
			if((m-n)&1)printf("2\n");
			else printf("1\n");
		}
	}
	return 0;
}