#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
pair<int,int> ask(char c)
{
	printf("%c\n",c);
	fflush(stdout);
	int x,y;
	scanf("%i %i",&x,&y);
	return make_pair(x,y);
}
const int N=105;
char base[N][N],R,L,D,U;
int par[N][N];
int Move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void BFS(int x, int y, int a, int b)
{
    queue<int> q;
    q.push(x*N+y);
    par[x][y]=-1;
    while(q.size())
	{
		x=q.front()/N;
		y=q.front()%N;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=x+Move[i][0];
			int ny=y+Move[i][1];
			if(base[nx][ny]=='.' && par[nx][ny]==0)
			{
				q.push(nx*N+ny);
				par[nx][ny]=i+1;
			}
		}
	}
	while(base[a][b]!='F')
	{
		if(par[a][b]==1) tie(a,b)=ask(U);
		else if(par[a][b]==2) tie(a,b)=ask(L);
		else if(par[a][b]==3) tie(a,b)=ask(D);
		else if(par[a][b]==4) tie(a,b)=ask(R);
	}
}
int main()
{
	int n,m,i,j;
    scanf("%i %i",&n,&m);
    for(i=1;i<=n;i++) scanf("%s",base[i]+1);
    pair<int,int> p=mp(1,1);
    if(base[1][2]=='*')
	{
		p=ask('D');
		if(p.first==2) D='D',U='U';
		else D='U',U='D';
		if(p.first==2) p=ask(U);
		while(p.first<=n)
		{
			if(base[p.first][p.second]=='F') return 0;
			if(base[p.first][2]!='*')
			{
				p=ask('R');
				if(p.second==2) R='R',L='L';
				else R='L',L='R';
				if(base[p.first][p.second]=='F') return 0;
				break;
			}
			p=ask(D);
		}
	}
	else
	{
		p=ask('R');
		if(p.second==2) R='R',L='L';
		else R='L',L='R';
		if(p.second==2) p=ask(L);
		while(p.second<=m)
		{
			if(base[p.first][p.second]=='F') return 0;
			if(base[2][p.second]!='*')
			{
				p=ask('D');
				if(p.first==2) D='D',U='U';
				else D='U',U='D';
				if(base[p.first][p.second]=='F') return 0;
				break;
			}
			p=ask(R);
		}
	}
	int x,y,a,b;a=p.first,b=p.second;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(base[i][j]=='F') x=i,y=j;
	BFS(x,y,a,b);
	return 0;
}