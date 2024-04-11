#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
}h,v;
int d,s,dist[505][5005],i,j,k,u,vv,x,y;
const int inf=1e9;
vector<node> ss[505];
queue<node> q;
int main()
{
	scanf("%d%d",&d,&s);
	for(i=0;i<d;i++)
	{
		for(j=0;j<10;j++)
		{
			u=(i*10+j)%d;
			ss[u].push_back((node){i,j});
		}
	}
	for(i=0;i<d;i++)for(j=0;j<=s;j++)dist[i][j]=inf;
	dist[0][s]=0;
	q.push((node){0,s});
	while(!q.empty())
	{
		h=q.front();
		q.pop();
		for(i=0;i<ss[h.x].size();i++)
		{
			v=ss[h.x][i];
			v.y=h.y-v.y;
			if(v.y>=0&&dist[v.x][v.y]==inf)
			{
				//printf("#%d %d %d\n",v.x,v.y,dist[v.x][v.y]);
				dist[v.x][v.y]=dist[h.x][h.y]+1;
				q.push((node){v.x,v.y});
			}
		}
	}
	if(dist[0][0]==inf)printf("-1");
	else
	{
		x=0;y=0;
		while(x!=0||y!=s)
		{
			for(i=0;i<10;i++)
			{
				u=(x*10+i)%d;
				vv=y+i;
				//printf("%d %d %d %d\n",u,vv,dist[u][vv],dist[x][y]);
				if(vv<=s&&dist[u][vv]==dist[x][y]-1)
				{
					//printf("^^%d %d %d %d\n",u,vv,dist[u][vv],dist[x][y]);
					x=u;y=vv;
					printf("%d",i);
					break;
				}
			}
		}
	}
	return 0;
}