#include<stdio.h>
#include<map>
#include<queue>
#define X first
#define Y second
using namespace std;
typedef pair<int,int>ii;
map<ii,int>d;
queue<ii>q;
int sx,sy,ex,ey,n,l,r,h;
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
int main()
{
	scanf("%d %d %d %d %d",&sx,&sy,&ex,&ey,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&h,&l,&r);
		for(int j=l;j<=r;j++)
			d[ii(h,j)]=-1;
	}
	d[ii(sx,sy)]=0;
	q.push(ii(sx,sy));
	while(q.size())
	{
		ii u=q.front();
		q.pop();
		for(int i=0;i<8;i++)
		{
			ii v=ii(u.X+dx[i],u.Y+dy[i]);
			if(d.count(v)&&d[v]==-1)
				d[v]=d[u]+1,q.push(v);
		}
	}
	printf("%d",d[ii(ex,ey)]);
	return 0;
}