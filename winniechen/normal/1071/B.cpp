#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 2005
struct node
{
	int x,y,dis;
	node(){}
	node(int a,int b,int c){x=a,y=b,dis=c;}
	node operator + (const node &a) const {return node(x+a.x,y+a.y,dis+a.dis);}
	bool operator < (const node &a) const {return dis<a.dis;}
}d[2];
int f[N][N],n,k,vis[N][N];char s[N][N],ans[N<<1];
priority_queue<node>q,tmp;
bool check(node x){return x.x>0&&x.x<=n&&x.y>0&&x.y<=n;}
int main()
{
	scanf("%d%d",&n,&k);d[0]=node(1,0,-1);d[1]=node(0,1,-1);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	if(!k)q.push(node(1,1,0)),ans[1]=s[1][1];
	else q.push(node(1,1,k-(s[1][1]!='a'))),ans[1]='a';
	f[1][1]=1;
	for(int i=2;i<(n<<1);i++)
	{
		int mn=26;
		while(!q.empty())
		{
			node x=q.top();q.pop();
			for(int j=0;j<2;j++)
			{
				node t=x+d[j];if(!check(t))continue;
				if(s[t.x][t.y]=='a'&&t.dis>=0)t.dis++;
				if(t.dis>=0)tmp.push(t),mn=0;
				else tmp.push(t),mn=min(s[t.x][t.y]-'a',mn);
			}
		}
		while(!tmp.empty())
		{
			node x=tmp.top();tmp.pop();
			if(vis[x.x][x.y])continue;
			if(x.dis>=0||s[x.x][x.y]=='a'+mn)vis[x.x][x.y]=1,q.push(x);
		}
		ans[i]=mn+'a';
	}
	printf("%s\n",ans+1);
}