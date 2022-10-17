#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x3f3f3f3f
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
struct N
{
	int x,y,mx,my;
};
queue<N>q;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m;
char s[3020][3020];
int v[3020][3020][2];
int sx,sy;
int main()
{
	scanf("%d %d",&n,&m);
	memset(v,0x3f,sizeof v);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
		for(int j=0;j<m;j++)
			if(s[i][j]=='S')
				sx=i,sy=j;
	}
	q.push((N){sx,sy,0,0});
	v[sx][sy][0]=0;
	v[sx][sy][1]=0;
	while(q.size())
	{
		N u=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=u.x+dx[i];
			int ny=u.y+dy[i];
			int nmx=u.mx;
			int nmy=u.my;
			int w=0;
			if(nx<0)
				nx+=n,nmx--;
			if(ny<0)
				ny+=m,nmy--;
			if(nx>=n)
				nx-=n,nmx++;
			if(ny>=m)
				ny-=m,nmy++;
			if(v[nx][ny][0]!=inf&&v[nx][ny][1]!=inf&&(v[nx][ny][0]!=nmx||v[nx][ny][1]!=nmy))
			{
				ans=1;
				goto end;
			}
			if(s[nx][ny]=='.'&&(v[nx][ny][0]!=nmx&&v[nx][ny][1]!=nmy))
			{
				v[nx][ny][0]=nmx;
				v[nx][ny][1]=nmy;
				q.push((N){nx,ny,nmx,nmy});
			}
		}
	}
	end:;
	puts(ans?"Yes":"No");
	return 0;
}