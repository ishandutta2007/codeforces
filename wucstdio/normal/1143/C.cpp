#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
bool flag[100005];
int main()
{
	scanf("%d",&n);
	memset(flag,1,sizeof(flag));
	for(int i=1;i<=n;i++)
	{
		int p,c;
		scanf("%d%d",&p,&c);
		if(c==0)flag[i]=0;
		if(p==-1)continue;
		if(c==0)flag[p]=0;
	}
	bool res=0;
	for(int i=1;i<=n;i++)
	{
		if(flag[i])
		{
			res=1;
			printf("%d ",i);
		}
	}
	if(res==0)printf("-1");
	printf("\n");
	return 0;
}