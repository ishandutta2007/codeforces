#include<cstdio>
#include<utility>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

int tx[1010],ty[1010];
int xs[1010],ys[1010];

bool field[2020][2020];
bool ng[2020][2020];

queue<P> que;

int main()
{
	int N;
	scanf("%d",&N);
	int cx=0,cy=0;
	tx[0]=0,ty[0]=0;
	for(int i=0;i<N;i++)
	{
		char ch[10];
		int dis;
		scanf("%s%d",ch,&dis);
		if(ch[0]=='R')
		{
			cx+=dis;
			tx[i+1]=cx,ty[i+1]=cy;
		}
		else if(ch[0]=='L')
		{
			cx-=dis;
			tx[i+1]=cx,ty[i+1]=cy;
		}
		else if(ch[0]=='U')
		{
			cy+=dis;
			tx[i+1]=cx,ty[i+1]=cy;
		}
		else
		{
			cy-=dis;
			tx[i+1]=cx,ty[i+1]=cy;
		}
	}
	for(int i=0;i<=N;i++) xs[i]=tx[i],ys[i]=ty[i];
	sort(xs,xs+N+1),sort(ys,ys+N+1);
	int xln=unique(xs,xs+N+1)-xs,yln=unique(ys,ys+N+1)-ys;
	memset(field,false,sizeof(field));
	for(int i=0;i<N;i++)
	{
		int px=lower_bound(xs,xs+xln,tx[i])-xs;
		int py=lower_bound(ys,ys+yln,ty[i])-ys;
		int nx=lower_bound(xs,xs+xln,tx[i+1])-xs;
		int ny=lower_bound(ys,ys+yln,ty[i+1])-ys;
		if(px==nx)
		{
			int xid=px*2+1;
			for(int j=min(ny,py)*2+1;j<=max(ny,py)*2+1;j++)
			{
				field[xid][j]=true;
			}
		}
		else
		{
			int yid=py*2+1;
			for(int j=min(nx,px)*2+1;j<=max(nx,px)*2+1;j++)
			{
				field[j][yid]=true;
			}
		}
	}
	memset(ng,false,sizeof(ng));
	que.push(P(0,0));
	while(!que.empty())
	{
		P p=que.front();
		que.pop();
		int x=p.first,y=p.second;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<0||ny<0||nx>xln*2||ny>yln*2) continue;
			int xl,yl;
			if(nx%2==0&&nx!=0&&nx!=xln*2) xl=xs[nx/2]-xs[nx/2-1]-1;
			else xl=1;
			if(ny%2==0&&ny!=0&&ny!=yln*2) yl=ys[ny/2]-ys[ny/2-1]-1;
			else yl=1;
			if(xl==0||yl==0)
			{
				nx+=dx[i],ny+=dy[i];
				if(nx<0||ny<0||nx>xln*2||ny>yln*2) continue;
			}
			if(field[nx][ny]==true) continue;
			if(ng[nx][ny]==true) continue;
			ng[nx][ny]=true;
			que.push(P(nx,ny));
		}
	}
	long long ans=0;
	for(int i=1;i<xln*2;i++)
	{
		for(int j=1;j<yln*2;j++)
		{
			if(ng[i][j]) continue;
			int x,y;
			if(i%2==0) x=xs[i/2]-xs[i/2-1]-1;
			else x=1;
			if(j%2==0) y=ys[j/2]-ys[j/2-1]-1;
			else y=1;
			ans+=(long long)x*y;
		}
	}
	cout<<ans<<"\n";
	return 0;
}