#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};
int n,m,a[105][105];
inline int read()
{
	char c=getchar();
	while((c>'9'||c<'0')&&c!='*'&&c!='.')c=getchar();
	if(c=='*')return -1;
	if(c=='.')return 0;
	return c-'0';
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    a[i][j]=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int num=0;
		for(int k=0;k<8;k++)
		  num+=a[i+dx[k]][j+dy[k]]==-1;
		if(num!=a[i][j]&&a[i][j]!=-1)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}