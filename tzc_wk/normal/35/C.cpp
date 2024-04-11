#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
#define maxn 2020
bool map[maxn][maxn];
int dis[maxn][maxn];
int xx[12];
int yy[12];
int heng[]={0,0,1,-1};
int zong[]={1,-1,0,0};
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		memset(dis,0x3f,sizeof(dis));
		memset(map,0,sizeof(map));
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int x,y;
			cin>>x>>y;
			xx[i]=x;
			yy[i]=y;
			map[x][y]=1;
			dis[x][y]=0;
		}
		for(int i=1;i<=k;i++)
		{
			queue <int> qx;
			queue <int> qy;
			qx.push(xx[i]);
			qy.push(yy[i]);
			while(!qx.empty())
			{
				int xxx=qx.front();
				int yyy=qy.front();
				qx.pop();
				qy.pop();
				map[xxx][yyy]=1;
				for(int j=0;j<4;j++)
				{
					int x_=xxx+heng[j];
					int y_=yyy+zong[j];
					if((x_>=1&&x_<=n)&&(y_>=1&&y_<=m))
					{
						if(dis[xxx][yyy]+1<dis[x_][y_])
						{
							dis[x_][y_]=dis[xxx][yyy]+1;
							qx.push(x_);
							qy.push(y_);
						}
					}
				}
			}
		}
		int las=-1;
		int lasx,lasy;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(dis[i][j]>las)
				{
					las=dis[i][j];
					lasx=i;
					lasy=j;
				}
			}
		}
		cout<<lasx<<" "<<lasy<<endl;
	}
	return 0;
}