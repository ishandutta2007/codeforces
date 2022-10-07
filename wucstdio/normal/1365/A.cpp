#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m;
bool f1[55],f2[55];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int x;
				scanf("%d",&x);
				if(x)f1[i]=f2[j]=x;
			}
		}
		int n1=0,n2=0;
		for(int i=1;i<=n;i++)
		  if(!f1[i])n1++;
		for(int i=1;i<=m;i++)
		  if(!f2[i])n2++;
		puts((min(n1,n2)&1)?"Ashish":"Vivek");
	}
	return 0;
}