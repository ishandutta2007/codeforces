#include<bits/stdc++.h>
#define maxn 305
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m,p;
vector<pii> v[maxn*maxn];
struct node
{
	pii pos;
	int dis;
	node(){}
	node(pii P,int D){pos=P;dis=D;}
};
bool operator < (node a,node b)
{
	return a.dis<b.dis;
}
int ans[maxn][maxn],dis[maxn][maxn];
bool vis[maxn][maxn];
int Ax,Ay;
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			int x;
			scanf("%d",&x);
			v[x].push_back(mp(i,j));
			if(x==p)Ax=i,Ay=j;
		}
	memset(ans,127/2,sizeof(ans));
	for(int i=0;i<v[1].size();++i)
	{
		int x=v[1][i].first,y=v[1][i].second;
		ans[x][y]=abs(x-1)+abs(y-1);
	}
	for(int i=2;i<=p;++i)
	{
		if(v[i-1].size()*v[i].size()<n*m)
		{
			for(int j=0;j<v[i].size();++j)
			{
				for(int k=0;k<v[i-1].size();++k)
				{
					int x=v[i][j].first,y=v[i][j].second;
					int u=v[i-1][k].first,w=v[i-1][k].second;
					ans[x][y]=min(ans[x][y],ans[u][w]+abs(x-u)+abs(y-w));
				}
			}
		}
		else
		{
			const int dx[]={-1,0,1,0};
			const int dy[]={0,-1,0,1};
			memset(dis,0,sizeof(dis));
			memset(vis,0,sizeof(vis));
			vector<node> t;
			queue<node> q1,q2;
			for(int j=0;j<v[i-1].size();++j)t.push_back(node(v[i-1][j],ans[v[i-1][j].first][v[i-1][j].second]));
			sort(t.begin(),t.end());
			for(int j=0;j<t.size();++j)
			{
				q2.push(t[j]);
				int x=t[j].pos.first,y=t[j].pos.second;
				vis[x][y]=1;
				dis[x][y]=t[j].dis;
			}
			while(!q1.empty()||!q2.empty())
			{
				node u;
				if(q1.empty())u=q2.front(),q2.pop();
				else if(q2.empty())u=q1.front(),q1.pop();
				else
				{
					if(q1.front().dis<q2.front().dis)u=q1.front(),q1.pop();
					else u=q2.front(),q2.pop();
				}
				int x=u.pos.first,y=u.pos.second;
				for(int k=0;k<4;++k)
				{
					int nx=x+dx[k],ny=y+dy[k],nd=u.dis+1;
					if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&(!vis[nx][ny]))
					{
						vis[nx][ny]=1;
						dis[nx][ny]=nd;
						q1.push(node(mp(nx,ny),nd));
					}
				}
			}
			for(int j=0;j<v[i].size();++j)
			{
				int x=v[i][j].first,y=v[i][j].second;
				ans[x][y]=dis[x][y]; 
			} 
		}
	}
	printf("%d\n",ans[Ax][Ay]);
	return 0;
}