#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};
int n,m,a[1005][1005],b[1005][1005];
inline int read()
{
	char c=getchar();
	while(c!='.'&&c!='#')c=getchar();
	return c=='#';
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    a[i][j]=read();
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		  printf("%d ",a[i][j]);
//		printf("\n");
//	}
	for(int i=2;i<n;i++)
	for(int j=2;j<m;j++)
	{
		bool f=1;
		for(int k=0;k<8;k++)
		if(a[i+dx[k]][j+dy[k]]==0)
		{
			f=0;
			break;
		}
		if(f)
		{
			for(int k=0;k<8;k++)
			  b[i+dx[k]][j+dy[k]]=1;
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i][j]!=b[i][j])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}