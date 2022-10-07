#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,q;
char s[25][25],t[25][25];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=m;i++)scanf("%s",t[i]+1);
	scanf("%d",&q);
	while(q--)
	{
		int x;
		scanf("%d",&x);
		x=(x-1)%(n*m)+1;
		int v1=1,v2=1;
		for(int i=2;i<=x;i++)
		{
			v1=v1%n+1;
			v2=v2%m+1;
		}
		printf("%s%s\n",s[v1]+1,t[v2]+1);
	}
	return 0;
}