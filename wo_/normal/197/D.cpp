#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<cstring>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

typedef pair<P,P> PP;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

bool field[1600][1600];

bool visited[1600][1600];

P ps[1600][1600];

int main()
{
	int N,M;
	int sx,sy;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		char ch[1600];
		scanf("%s",ch);
		for(int j=0;j<M;j++)
		{
			if(ch[j]=='#') field[i][j]=false;
			else field[i][j]=true;
			if(ch[j]=='S')
			{
				sx=i,sy=j;
			}
		}
	}
	/*
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(field[i][j]=='#') continue;
			if(i==0)
			{
				if(field[N-1][j]==false) field[0][j]=false;
			}
			if(i==N-1) if(field[0][j]==false) field[i][j]=false;
			if(j==0) if(field[i][M-1]==false) field[i][0]=false;
			if(j==M-1) if(field[i][0]==false) field[i][j]=false;
		}
	}
	*/
	queue<PP> que;
	que.push(PP(P(sx,sy),P(0,0)));
	memset(visited,false,sizeof(visited));
	//visited[sx][sy]=true;
	//ps[sx][sy]=P(0,0);
	while(!que.empty())
	{
		PP pp=que.front();
		que.pop();
		int x=pp.first.first;
		int y=pp.first.second;
		int mx=pp.second.first;
		int my=pp.second.second;
		//printf("%d %d %d %d\n",x,y,mx,my);
		if(visited[x][y]==true)
		{
			if(mx!=ps[x][y].first||my!=ps[x][y].second)
			{
			//	printf("%d %d %d %d %d %d\n",x,y,ps[x][y].first,ps[x][y].second,mx,my);
				printf("YES\n");
				return 0;
			}
			else continue;
		}
		visited[x][y]=true;
		ps[x][y]=P(mx,my);
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			int nmx=mx,nmy=my;
			if(nx==-1)
			{
				nx=N-1;
				nmx=mx-1;
			}
			if(nx==N)
			{
				nx=0;
				nmx=mx+1;
			}
			if(ny==-1)
			{
				ny=M-1;
				nmy=my-1;
			}
			if(ny==M)
			{
				ny=0;
				nmy=my+1;
			}
			//visited[nx][ny]=true;
			//ps[nx][ny]=P(nmx,nmy);
			if(field[nx][ny]==false) continue;
			que.push(PP(P(nx,ny),P(nmx,nmy)));
			//printf("push:%d %d %d %d\n",nx,ny,nmx,nmy);
		}
	}
	printf("NO\n");
	return 0;
}