#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool f[360],g[360];
int n;
int main()
{
	scanf("%d",&n);
	g[0]=1;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		for(int j=0;j<360;j++)
		  f[j]=g[(j+x)%360]|g[(j-x+360)%360];
		for(int j=0;j<360;j++)
		  g[j]=f[j];
	}
	if(f[0])printf("YES\n");
	else printf("NO\n");
	return 0;
}