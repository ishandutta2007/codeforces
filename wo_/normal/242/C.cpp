#include<cstdio>
#include<utility>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

const int dx[]={1,1,1,0,-1,-1,-1,0};
const int dy[]={1,0,-1,-1,-1,0,1,1};

typedef pair<int,int> P;

P valid[100100];

map<P,int> dis;

int main()
{
	int sx,sy,gx,gy;
	int N;
	scanf("%d%d%d%d",&sx,&sy,&gx,&gy);
	scanf("%d",&N);
	int m=0;
	for(int i=0;i<N;i++)
	{
		int r,a,b;
		scanf("%d%d%d",&r,&a,&b);
		for(int s=a;s<=b;s++)
		{
			valid[m]=P(r,s);
			m++;
		}
	}
	sort(valid,valid+m);
	int vln=unique(valid,valid+m)-valid;
	dis[P(sx,sy)]=0;
	queue<P> que;
	que.push(P(sx,sy));
	while(!que.empty())
	{
		P p=que.front();
		que.pop();
		int d=dis[p];
		for(int i=0;i<8;i++)
		{
			int nx=p.first+dx[i],ny=p.second+dy[i];
			if(binary_search(valid,valid+vln,P(nx,ny))==false) continue;
			if(dis.count(P(nx,ny))>0&&dis[P(nx,ny)]<=d+1) continue;
			dis[P(nx,ny)]=d+1;
			que.push(P(nx,ny));
		}
	}
	if(dis.count(P(gx,gy))==0) printf("-1\n");
	else printf("%d\n",dis[P(gx,gy)]);
	return 0;
}