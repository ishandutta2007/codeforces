#include <stdio.h>
#include <queue>
using namespace std;
#define mp make_pair
const int inf=1e9;
int dist[105][100050],a[100050];
queue< pair<int,int> > q;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,i,j,x1,y1,x2,y2;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),a[i]++;
	for(i=1;i<=n;i++) for(j=1;j<100050;j++) dist[i][j]=inf;
	scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
	dist[x1][y1]=0;
	q.push(mp(x1,y1));
	int nx,ny;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		if(x>1)
		{
			nx=x-1;
			ny=y;
			if(a[nx]<ny) ny=a[nx];
			if(dist[nx][ny]==inf)
			{
				dist[nx][ny]=dist[x][y]+1;
				q.push(mp(nx,ny));
			}
		}
		if(x<n)
		{
			nx=x+1;
			ny=y;
			if(a[nx]<ny) ny=a[nx];
			if(dist[nx][ny]==inf)
			{
				dist[nx][ny]=dist[x][y]+1;
				q.push(mp(nx,ny));
			}
		}
		if(y>1)
		{
			nx=x;
			ny=y-1;
			if(dist[nx][ny]==inf)
			{
				dist[nx][ny]=dist[x][y]+1;
				q.push(mp(nx,ny));
			}
		}
		if(y<a[x])
		{
			nx=x;
			ny=y+1;
			if(dist[nx][ny]==inf)
			{
				dist[nx][ny]=dist[x][y]+1;
				q.push(mp(nx,ny));
			}
		}
	}
	printf("%i\n",dist[x2][y2]);
	return 0;
}