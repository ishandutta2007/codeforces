#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
inline int read()
{
	char c=getchar();
	while(c!='0'&&c!='1'&&c!='.')c=getchar();
	if(c=='.')return -1;
	return c=='1';
}
int n,p,a[2005];
void output()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1)printf("0");
		else printf("%d",a[i]);
	}
	printf("\n");
}
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
	  a[i]=read();
	for(int i=1;i+p<=n;i++)
	{
		if(a[i]==-1&&a[i+p]==-1)
		{
			a[i]=0,a[i+p]=1;
			output();
			return 0;
		}
		if(a[i]==-1)
		{
			a[i]=!a[i+p];
			output();
			return 0;
		}
		if(a[i+p]==-1)
		{
			a[i+p]=!a[i];
			output();
			return 0;
		}
		if(a[i]!=a[i+p])
		{
			output();
			return 0;
		}
	}
	printf("No\n");
	return 0;
}