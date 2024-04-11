#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m,a[35][35],num[75][2];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(num,0,sizeof(num));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			num[min(i+j-2+1,n+m-(i+j)+1)][a[i][j]]++;
		}
		int ans=0;
		for(int i=1;i<=(n+m-1)/2;i++)ans+=min(num[i][0],num[i][1]);
		printf("%d\n",ans);
	}
	return 0;
}