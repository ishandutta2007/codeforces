#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 2005
int n,m,tx,ty,sx,sy;char map[N][N];
struct node
{
	int x,y;
	node(){}
	node(int a){x=(a-1)/m+1,y=(a-1)%m+1;}
	node(int a,int b){x=a,y=b;}
	int zip(){return (x-1)*m+y;}
	node operator + (const node &a) const {return node(x+a.x,y+a.y);}
	bool check(){return x<=n&&x>=1&&y<=m&&y>=1&&map[x][y]!='*';}
	bool operator < (const node &a) const {return x+y<a.x+a.y;}
}dis[N*N],d[4];
deque<node>q;
void bfs(node S)
{
	q.push_front(S);dis[S.zip()]=node(0,0);
	while(!q.empty())
	{
		node x=q.front();q.pop_front();
		for(int i=2;i<4;i++)
		{
			node t=d[i]+x;if(!t.check())continue;
			if(dis[x.zip()]<dis[t.zip()])
			{
				q.push_front(t);
				dis[t.zip()]=dis[x.zip()];
			}
		}
		for(int i=0;i<2;i++)
		{
			node t=d[i]+x;if(!t.check())continue;node tmp=dis[x.zip()]+(i?node(1,0):node(0,1));
			if(tmp<dis[t.zip()])
			{
				q.push_back(t);
				dis[t.zip()]=tmp;
			}
		}
	}
}
int main()
{
	d[0]=node(0,1);d[1]=node(0,-1);d[2]=node(1,0);d[3]=node(-1,0);memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&tx,&ty);
	for(int i=1;i<=n;i++)scanf("%s",map[i]+1);
	bfs(node(sx,sy));int ret=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		if(dis[(i-1)*m+j].x<=tx&&dis[(i-1)*m+j].y<=ty)ret++;
	// for(int i=1;i<=n;i++)printf("%s\n",map[i]+1);
	printf("%d\n",ret);
}