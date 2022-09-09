#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int Move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int N=255;
long long Matrix[N][N];
int TMP[N][N];
bool base[N][N];
char ch[N];
queue< pair<int,int> > qu;
vector< pair<int, pair<int,int> > > start;
int n,m,q;
void BFS(int x, int y, int v)
{
	int i,j;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) TMP[i][j]=0;
	TMP[x][y]=v*q;
	qu.push(make_pair(x,y));
	while(!qu.empty())
	{
		x=qu.front().first;
		y=qu.front().second;
		qu.pop();
		Matrix[x][y]+=TMP[x][y];
		for(i=0;i<4;i++)
		{
			int nx=x+Move[i][0];
			int ny=y+Move[i][1];
			if(base[nx][ny] && !TMP[nx][ny])
			{
				TMP[nx][ny]=TMP[x][y]/2;
				if(TMP[nx][ny]) qu.push(make_pair(nx,ny));
			}
		}
	}
	//for(i=1;i<=n;i++) for(j=1;j<=m;j++) Matrix[i][j]+=TMP[i][j];
}
int main()
{
	int i,j,p;
	scanf("%i %i %i %i",&n,&m,&q,&p);
	for(i=1;i<=n;i++)
	{
		scanf("%s",&ch);
		for(j=1;j<=m;j++)
		{
			if(ch[j-1]=='.') base[i][j]=true;
			else if(ch[j-1]=='*') base[i][j]=false;
			else base[i][j]=true,start.push_back(make_pair(ch[j-1]-'A'+1,make_pair(i,j)));
		}
	}
	for(i=0;i<start.size();i++)
	{
		BFS(start[i].second.first,start[i].second.second,start[i].first);
	}
	int sol=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(Matrix[i][j]>p) sol++;
		}
	}
	printf("%i\n",sol);
	return 0;
}