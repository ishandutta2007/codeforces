#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,m,p;
char a[maxn][maxn];
int s[maxn];
struct node
{
	int x,y;
	node(){}
	node(int X,int Y){x=X;y=Y;}
};
queue<node> q[10];
stack<node> stk;
int dis[maxn][maxn];
int Ans[10];
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=p;++i)scanf("%d",&s[i]);
	for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			int k=a[i][j]-'0';
			if(1<=k&&k<=p)q[k].push(node(i,j)); 
		}
	while(1)
	{
		for(int k=1;k<=p;++k)
		{
			while(!q[k].empty())
			{
				node u=q[k].front();
				q[k].pop();
				int x=u.x,y=u.y;
				if(a[x-1][y]=='.'||a[x+1][y]=='.'||a[x][y-1]=='.'||a[x][y+1]=='.')
				{
					stk.push(u);
					dis[x][y]=0;
				}
			}
			while(!stk.empty())
			{
				q[k].push(stk.top());
				stk.pop(); 
			}
		}
		int flag=0;
		for(int k=1;k<=p;++k)if(!q[k].empty())flag=1;
		if(!flag)break;
		for(int k=1;k<=p;++k)
		{
			while(!q[k].empty())
			{
				node u=q[k].front();q[k].pop();
				int x=u.x,y=u.y;
				if(dis[x][y]==s[k])
				{
					stk.push(u);
					continue;
				}
				if(a[x-1][y]=='.')
				{
					dis[x-1][y]=dis[x][y]+1;
					a[x-1][y]='0'+k;
					q[k].push(node(x-1,y));
				}
				if(a[x+1][y]=='.')
				{
					dis[x+1][y]=dis[x][y]+1;
					a[x+1][y]='0'+k;
					q[k].push(node(x+1,y));
				}
				if(a[x][y-1]=='.')
				{
					dis[x][y-1]=dis[x][y]+1;
					a[x][y-1]='0'+k;
					q[k].push(node(x,y-1));
				}
				if(a[x][y+1]=='.')
				{
					dis[x][y+1]=dis[x][y]+1;
					a[x][y+1]='0'+k;
					q[k].push(node(x,y+1));
				}
			}
			while(!stk.empty())
			{
				node u=stk.top();
				stk.pop();
				q[k].push(u);
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			int k=a[i][j]-'0';
			if(1<=k&&k<=p)Ans[k]++;
		}
	for(int i=1;i<=p;++i)printf("%d ",Ans[i]);
	return 0; 
}