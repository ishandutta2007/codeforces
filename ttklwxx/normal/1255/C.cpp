#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int cx[100001][4],siz[100001],p[100001][4],ans[100001];
bool vis[100001];
int main()
{
    int n,qs=0,flag;
    n=read();
    for(int i=1;i<=n-2;i++)
    {
    	p[i][1]=read();
    	cx[p[i][1]][++siz[p[i][1]]]=i;
    	p[i][2]=read();
    	cx[p[i][2]][++siz[p[i][2]]]=i;
    	p[i][3]=read();
    	cx[p[i][3]][++siz[p[i][3]]]=i;
	}
	for(int i=1;i<=n;i++)if(siz[i]==1)
	{
		qs=i;
		break; 
	} 
	printf("%d ",qs);
	vis[qs]=1;
	ans[1]=qs;
	for(int i=1;i<=3;i++)if(siz[p[cx[qs][1]][i]]==2)
	{
		printf("%d ",p[cx[qs][1]][i]);
		vis[p[cx[qs][1]][i]]=1;
		qs=p[cx[qs][1]][i];
		ans[2]=p[cx[qs][1]][i];
		break;
	}
	int tflag;
	for(int i=3;i<=n;i++)
	{
		flag=0;
		for(int j=1;j<=siz[qs];j++)
		{
			for(int k=1;k<=3;k++)
			{
				if(!vis[p[cx[qs][j]][k]])
				{
					tflag=0;
					for(int tsth=1;tsth<=3;tsth++)
					{
						if(tsth!=k&&!vis[p[cx[qs][j]][tsth]])
						{
							tflag=1;
							break;
						}
					}
					if(tflag==1)continue;
					flag=1;
					printf("%d ",p[cx[qs][j]][k]);
					vis[p[cx[qs][j]][k]]=1;
					qs=p[cx[qs][j]][k];
					break;
				}
			}
			if(flag==1)break;
		}
	}
	return 0;
}