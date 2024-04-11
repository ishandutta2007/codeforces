#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct Point
{
	int x,y,t;
	Point(int xx=0,int yy=0,int tt=0){x=xx,y=yy,t=tt;}
};
int n,m,q,now,col[305][305],pos[305][305],pa[90005],last[2000005];
long long cnt[2000005];
vector<Point>a1[2000005],a2[2000005];
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return;
	pa[y]=x,now--;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    pos[i][j]=(i-1)*m+j;
	for(int c=0;c<=2000000;c++)last[c]=q+1;
	for(int i=1;i<=q;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		if(col[x][y]!=c)last[col[x][y]]=min(last[col[x][y]],i);
		a2[col[x][y]].push_back(Point(x,y,i));
		col[x][y]=c;
		a1[col[x][y]].push_back(Point(x,y,i));
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    a2[col[i][j]].push_back(Point(i,j,q+1));
	for(int c=0;c<=2000000;c++)
	{
		if(a1[c].empty())continue;
//		printf("c=%d:\n",c);
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
		    pa[pos[i][j]]=pos[i][j],col[i][j]=-1;
		now=0;
		int s=(int)a1[c].size();
		for(int i=0;i<s;i++)
		{
			Point p=a1[c][i];
			if(col[p.x][p.y]==-1)now++;
			col[p.x][p.y]=c;
			if(p.x!=1&&col[p.x-1][p.y]==c)merge(pos[p.x-1][p.y],pos[p.x][p.y]);
			if(p.y!=1&&col[p.x][p.y-1]==c)merge(pos[p.x][p.y-1],pos[p.x][p.y]);
			if(p.x!=n&&col[p.x+1][p.y]==c)merge(pos[p.x+1][p.y],pos[p.x][p.y]);
			if(p.y!=m&&col[p.x][p.y+1]==c)merge(pos[p.x][p.y+1],pos[p.x][p.y]);
//			printf("[%d,%d\n",p.t,now);
			cnt[p.t]+=now;
			if(i!=s-1)cnt[a1[c][i+1].t]-=now;
			else cnt[last[c]]-=now;
		}
	}
	for(int c=0;c<=2000000;c++)
	{
		if(a2[c].empty())continue;
//		printf("c=%d,last=%d:\n",c,last[c]);
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
		    pa[pos[i][j]]=pos[i][j],col[i][j]=-1;
		now=0;
		int s=(int)a2[c].size();
		for(int i=s-1;i>=0;i--)
		{
			Point p=a2[c][i];
			if(col[p.x][p.y]==-1)now++;
			col[p.x][p.y]=c;
			if(p.x!=1&&col[p.x-1][p.y]==c)merge(pos[p.x-1][p.y],pos[p.x][p.y]);
			if(p.y!=1&&col[p.x][p.y-1]==c)merge(pos[p.x][p.y-1],pos[p.x][p.y]);
			if(p.x!=n&&col[p.x+1][p.y]==c)merge(pos[p.x+1][p.y],pos[p.x][p.y]);
			if(p.y!=m&&col[p.x][p.y+1]==c)merge(pos[p.x][p.y+1],pos[p.x][p.y]);
			cnt[p.t]-=now;
//			printf("[%d,%d\n",p.t,now);
			if(i!=0)cnt[a2[c][i-1].t]+=now;
			else cnt[last[c]]+=now;
		}
	}
	long long ans=0;
	for(int i=1;i<=q;i++)
	{
		ans+=cnt[i];
		printf("%lld\n",ans);
	}
	return 0;
}