#include <bits/stdc++.h>
using namespace std;
const int Maxn=1005,dx[]={0,0,-1,0,1},dy[]={0,-1,0,1,0};
int n,m,p,s[13],cnt[13],mini[Maxn][Maxn];
char ch[Maxn][Maxn];
struct sta
{
	int x,y,dis,id;
	bool operator < (const sta &tmp) const
	{
		if(id==tmp.id) return dis>tmp.dis;
		if(dis/s[id]!=tmp.dis/s[tmp.id]) return dis/s[id]>tmp.dis/s[tmp.id];
		if(!((dis/s[id]==dis/(double)s[id])^(tmp.dis/s[tmp.id]==tmp.dis/(double)s[tmp.id])))
			return id>tmp.id;
		else return (dis/s[id]==dis/(double)s[id])>(tmp.dis/s[tmp.id]==tmp.dis/(double)s[tmp.id]);
	}
};
priority_queue <sta> Pr;
void bfs()
{
	while(!Pr.empty())
	{
		sta u=Pr.top();
		Pr.pop();
		for(int i=1;i<=4;i++)
		{
			int x=u.x+dx[i],y=u.y+dy[i];
			if(x<1||x>n||y<1||y>m) continue;
			if(ch[x][y]!='#'&&!isdigit(ch[x][y])&&!mini[x][y])
			{
				mini[x][y]=u.dis+1;
				cnt[u.id]++;
				Pr.push((sta){x,y,u.dis+1,u.id});
			}
		}
	}
}
int main()
{
//	freopen("D.in","r",stdin);
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=p;i++)
		scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)
	{
		getchar();
		for(int j=1;j<=m;j++)
		{
			ch[i][j]=getchar();
			while(!(isdigit(ch[i][j])||ch[i][j]=='.'||ch[i][j]=='#')) ch[i][j]=getchar();
			if(isdigit(ch[i][j]))
				Pr.push((sta){i,j,0,ch[i][j]-'0'}),cnt[ch[i][j]-'0']++;
		}
	}
	bfs();
	for(int i=1;i<=p;i++)
		printf("%d ",cnt[i]);
	return 0;
}