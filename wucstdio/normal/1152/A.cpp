#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,num1,num2;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		if(v&1)num1++;
		else num2++;
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int v;
		scanf("%d",&v);
		if(v&1)
		{
			if(num2)num2--,ans++;
		}
		else
		{
			if(num1)num1--,ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}