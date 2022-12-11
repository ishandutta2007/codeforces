#include <bits/stdc++.h>
#define Maxn 107
using namespace std;
int n,m;
bool g[Maxn][Maxn];
char s[Maxn],a[Maxn];
int nowx,nowy,x,y,len,ans=0;
int tx[4]={1,-1,0,0};
int ty[4]={0,0,1,-1};
bool vis[10];
int p[10];
void check()
{
	int now1=nowx,now2=nowy;
	for (int i=1;i<=len;i++)
	{
		int xx=now1+tx[p[a[i]-'0']];
		int yy=now2+ty[p[a[i]-'0']];
		if (xx<1||xx>n||yy<1||yy>m) return;
		if (!g[xx][yy]) return;
		now1=xx,now2=yy;
		if (now1==x&&now2==y)
		{
			++ans;
			return;
		}
	}
}
void dfs(int now)
{
	if (now>=4) check();
	else
	{
		for (int i=0;i<=3;i++)
			if (!vis[i])
			{
				p[now]=i;
				vis[i]=true;
				dfs(now+1);
				vis[i]=false;
			}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
		{
			if (s[j]=='#') g[i][j]=false; else g[i][j]=true;
			if (s[j]=='S')
			{
				nowx=i;
				nowy=j;
			}
			if (s[j]=='E')
			{
				x=i;
				y=j;
			}
		}
	}
	scanf("%s",a+1);
	len=strlen(a+1);
	memset(vis,false,sizeof(vis));
	memset(p,0,sizeof(p));
	dfs(0);
	printf("%d\n",ans);
	return 0;
}