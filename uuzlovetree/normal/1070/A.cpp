#include<bits/stdc++.h>
#define maxd 505
#define maxs 5005
using namespace std;
int d,s;
struct node
{
	int x,y;
	node(int X=0,int Y=0){x=X;y=Y;}
};
bool vis[maxd][maxs];
node pre[maxd][maxs];
int main()
{
	scanf("%d%d",&d,&s);
	queue<node> q;
	q.push(node(0,0));
	vis[0][0]=1;
	while(!q.empty())
	{
		node u=q.front();q.pop();
		int x=u.x,y=u.y;
		for(int i=0;i<=9;++i)
		{
			node v=node((x*10+i)%d,y+i);
			if(v.y>s)continue;
			if(vis[v.x][v.y])continue;
			pre[v.x][v.y]=u;
			q.push(v);
			vis[v.x][v.y]=1;
		}
	}
	if(!vis[0][s])
	{
		puts("-1");
		return 0;
	}
	stack<int> stk;
	node u=node(0,s);
	while(1)
	{
		node v=pre[u.x][u.y];
		stk.push(u.y-v.y);
		if(v.x==0&&v.y==0)break;
		u=v;
	}
	while(!stk.empty())
	{
		int x=stk.top();
		stk.pop();
		printf("%d",x);
	}
	return 0;
}