#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=55;
const int inf=1e9+7;
vector<pair<int,int>> f,s;
char base[N][N];
bool was[N][N];
int Move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
	int n,x,y,X,Y,i,j;
	scanf("%i",&n);
	scanf("%i %i",&x,&y);
	scanf("%i %i",&X,&Y);
	for(i=1;i<=n;i++) scanf("%s",base[i]+1);
	queue<int> q;
	q.push(x*N+y);
	was[x][y]=1;
	while(q.size())
	{
        int u=q.front()/N;
        int v=q.front()%N;
        q.pop();
        f.pb(mp(u,v));
        for(i=0;i<4;i++)
		{
			int nx=u+Move[i][0];
			int ny=v+Move[i][1];
			if(!was[nx][ny] && base[nx][ny]=='0')
			{
				was[nx][ny]=1;
				q.push(nx*N+ny);
			}
		}
	}
	if(was[X][Y]) return 0*printf("0\n");
	q.push(X*N+Y);
	was[X][Y]=1;
	while(q.size())
	{
        int u=q.front()/N;
        int v=q.front()%N;
        q.pop();
        s.pb(mp(u,v));
        for(i=0;i<4;i++)
		{
			int nx=u+Move[i][0];
			int ny=v+Move[i][1];
			if(!was[nx][ny] && base[nx][ny]=='0')
			{
				was[nx][ny]=1;
				q.push(nx*N+ny);
			}
		}
	}
	int ans=inf;
	for(auto p:f) for(auto q:s)
	{
		ans=min(ans,(p.first-q.first)*(p.first-q.first)+(p.second-q.second)*(p.second-q.second));
	}
	printf("%i\n",ans);
	return 0;
}