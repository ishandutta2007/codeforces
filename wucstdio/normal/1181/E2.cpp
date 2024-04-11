#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Point
{
	int x,y;
	Point(int xx=0,int yy=0){x=xx,y=yy;}
	bool operator<(Point p){return x<p.x||(x==p.x&&y<p.y);}
}p[4][100005];
int n,head[400005][4],tail[400005][4],pre[4][400005],nxt[4][400005];
int tmp[4][400005],top,tot;
bool cmp0(int a,int b)
{
	return p[0][a]<p[0][b];
}
bool cmp1(int a,int b)
{
	return p[1][a]<p[1][b];
}
bool cmp2(int a,int b)
{
	return p[2][a]<p[2][b];
}
bool cmp3(int a,int b)
{
	return p[3][a]<p[3][b];
}
void del(int*head,int*tail,int x)
{
	++top;
	for(int k=0;k<4;k++)
	{
		if(head[k]==x)
		{
			pre[k][nxt[k][x]]=0;
			head[k]=nxt[k][x];
		}
		else if(tail[k]==x)
		{
			nxt[k][pre[k][x]]=0;
			tail[k]=pre[k][x];
		}
		else
		{
			pre[k][nxt[k][x]]=pre[k][x];
			nxt[k][pre[k][x]]=nxt[k][x];
		}
		tmp[k][top]=x;
	}
}
void solve(int t,int size)
{
	if(size==1)return;
	int now[4],maxy[4];
	now[0]=head[t][0],now[1]=head[t][1],now[2]=head[t][2],now[3]=head[t][3];
	maxy[0]=maxy[1]=maxy[2]=maxy[3]=-1000000000;
	while(now[0]!=tail[t][0])
	{
		for(int k=0;k<4;k++)
		{
			maxy[k]=max(maxy[k],p[k][now[k]].y);
			now[k]=nxt[k][now[k]];
			if(maxy[k]>p[k][now[k]].x)continue;
			top=0;
			for(int i=head[t][k];i!=now[k];i=nxt[k][i])
				del(head[t],tail[t],i);
			sort(tmp[0]+1,tmp[0]+top+1,cmp0);
			sort(tmp[1]+1,tmp[1]+top+1,cmp1);
			sort(tmp[2]+1,tmp[2]+top+1,cmp2);
			sort(tmp[3]+1,tmp[3]+top+1,cmp3);
			++tot;
			for(int x=0;x<4;x++)
			{
				for(int i=2;i<top;i++)
				{
					pre[x][tmp[x][i]]=tmp[x][i-1];
					nxt[x][tmp[x][i]]=tmp[x][i+1];
				}
				nxt[x][tmp[x][1]]=tmp[x][2];
				pre[x][tmp[x][top]]=tmp[x][top-1];
				head[tot][x]=tmp[x][1];
				tail[tot][x]=tmp[x][top];
			}
			solve(t,size-top);
			solve(tot,top);
			return;
		}
	}
	printf("NO\n");
	exit(0);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		p[0][i]=Point(a,c);
		p[1][i]=Point(-c,-a);
		p[2][i]=Point(b,d);
		p[3][i]=Point(-d,-b);
		tmp[0][i]=i;
		tmp[1][i]=i;
		tmp[2][i]=i;
		tmp[3][i]=i;
	}
	top=n;
	sort(tmp[0]+1,tmp[0]+n+1,cmp0);
	sort(tmp[1]+1,tmp[1]+n+1,cmp1);
	sort(tmp[2]+1,tmp[2]+n+1,cmp2);
	sort(tmp[3]+1,tmp[3]+n+1,cmp3);
	++tot;
	for(int x=0;x<4;x++)
	{
		for(int i=2;i<top;i++)
		{
			pre[x][tmp[x][i]]=tmp[x][i-1];
			nxt[x][tmp[x][i]]=tmp[x][i+1];
		}
		nxt[x][tmp[x][1]]=tmp[x][2];
		pre[x][tmp[x][top]]=tmp[x][top-1];
		head[tot][x]=tmp[x][1];
		tail[tot][x]=tmp[x][top];
	}
	solve(1,n);
	printf("YES\n");
	return 0;
}