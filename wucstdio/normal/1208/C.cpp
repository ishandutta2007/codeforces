#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans[1005][1005];
int main()
{
	scanf("%d",&n);
	int tot=0;
	for(int i=1;i<=n/2;i++)
	for(int j=1;j<=n/2;j++)
	{
		ans[i][j]=tot*4;
		ans[i][j+n/2]=tot*4+1;
		ans[i+n/2][j]=tot*4+2;
		ans[i+n/2][j+n/2]=tot*4+3;
		tot++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		  printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}