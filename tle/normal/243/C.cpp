#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n,xx[2333333],yy[2333333];
int xp[2333],yp[4444];
int xn=0,lsx[2333333];
int yn=0,lsy[2333333];
typedef long long ll;
ll area[3333][3333];
bool bl[2333][2333],ift[2333][2333];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
typedef pair<int,int> pos;
queue<pos> bq;
void dfs(int x,int y)
{
	while(!bq.empty()) bq.pop();
	bq.push(pos(x,y));
	while(!bq.empty())
	{
		x=bq.front().first, y=bq.front().second; bq.pop();
		if(ift[x][y]||bl[x][y]) continue;
		ift[x][y]=1;
		for(int k=0;k<4;k++)
		{
			int xx=x+dx[k],yy=y+dy[k];
			if(xx>=1&&xx<=xn&&yy>=1&&yy<=yn) bq.push(pos(xx,yy));
		}
	}
}
int main()
{
	xp['R']=1; xp['L']=-1;
	yp['U']=1; yp['D']=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char d[4]; int x;
		scanf("%s%d",d,&x);
		xx[i]=xx[i-1]+xp[d[0]]*x;
		yy[i]=yy[i-1]+yp[d[0]]*x;
	}
	for(int i=0;i<=n;i++)
	{
		lsx[++xn]=xx[i];
		lsy[++yn]=yy[i];
		lsx[++xn]=xx[i]+1;
		lsy[++yn]=yy[i]+1;
	}
	sort(lsx+1,lsx+1+xn); xn=unique(lsx+1,lsx+1+xn)-lsx-1;
	sort(lsy+1,lsy+1+yn); yn=unique(lsy+1,lsy+1+yn)-lsy-1;
	for(int i=1;i<=n;i++)
	{
		int x1=xx[i-1],y1=yy[i-1],x2=xx[i],y2=yy[i];
		if(x1>x2) swap(x1,x2); if(y1>y2) swap(y1,y2);
		x1=lower_bound(lsx+1,lsx+1+xn,x1)-lsx;
		x2=lower_bound(lsx+1,lsx+1+xn,x2)-lsx;
		y1=lower_bound(lsy+1,lsy+1+yn,y1)-lsy;
		y2=lower_bound(lsy+1,lsy+1+yn,y2)-lsy;
		for(int x=x1;x<=x2;x++)
		{
			for(int y=y1;y<=y2;y++) bl[x][y]=1;
		}
	}
	for(int i=1;i<=xn;i++)
	{
		for(int j=1;j<=yn;j++)
		{
			area[i][j]=ll(lsx[i+1]-lsx[i])*(lsy[j+1]-lsy[j]);
		}
	}
	for(int i=1;i<=xn;i++)
	{
		for(int j=1;j<=yn;j++)
		{
			if(i!=1&&i!=xn&&j!=1&&j!=yn) continue;
			dfs(i,j);
		}
	}
	ll gs=0;
	for(int i=1;i<=xn;i++)
	{
		for(int j=1;j<=yn;j++) gs+=(!ift[i][j])*area[i][j];
	}
	cout<<gs<<"\n";
}