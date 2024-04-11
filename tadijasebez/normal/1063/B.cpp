#include <bits/stdc++.h>
using namespace std;
const int N=2050;
const int inf=2e9+7;
int dist[N][N];
bool was[N][N];
int Move[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char Base[N][N];
int main()
{
	int n,m,r,c,x,y,i,j;
	scanf("%i %i",&n,&m);
	scanf("%i %i",&r,&c);
	scanf("%i %i",&x,&y);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) dist[i][j]=inf;
	for(i=1;i<=n;i++) scanf("%s",Base[i]+1);
	deque<int> q;
	q.push_front(r*N+c);
	dist[r][c]=0;
	while(q.size())
	{
		int X=q.front()/N;
		int Y=q.front()%N;
		q.pop_front();
		was[X][Y]=1;
		for(int i=0;i<4;i++)
		{
			int nx=X+Move[i][0];
			int ny=Y+Move[i][1];
			if(Base[nx][ny]!='.') continue;
			if(i<2)
			{
				if(dist[nx][ny]>dist[X][Y])
				{
					dist[nx][ny]=dist[X][Y];
					q.push_front(nx*N+ny);
				}
			}
			else
			{
				if(dist[nx][ny]>dist[X][Y]+1)
				{
					dist[nx][ny]=dist[X][Y]+1;
					q.push_back(nx*N+ny);
				}
			}
		}
	}
	int sol=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(dist[i][j]==inf) continue;
			int d=abs(c-j);
			int L,R;
			if(j<c)
			{
				L=d+(dist[i][j]-d)/2;
				R=(dist[i][j]-d)/2;
			}
			else
			{
				L=(dist[i][j]-d)/2;
				R=d+(dist[i][j]-d)/2;
			}
			//printf("(%i %i) %i %i\n",i,j,L,R);
			if(L<=x && R<=y) sol++;
		}
	}
	printf("%i\n",sol);
	return 0;
}