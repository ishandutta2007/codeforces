#include <bits/stdc++.h>
#define Maxn 2007
using namespace std;
int n,k;
char s[Maxn][Maxn];
int f[Maxn][Maxn];
bool vis[Maxn][Maxn];
set<pair<int,int> > now,now1;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	if (n==1)
	{
		if (k==1) printf("%c\n",'a'); else printf("%c\n",s[1][1]);
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			if (i==1&&j==1)
			{
				f[i][j]=1;
				if (s[i][j]=='a') f[i][j]=0;
			} else
			{
				f[i][j]=n*n;
				if (i>1) f[i][j]=min(f[i][j],f[i-1][j]);
				if (j>1) f[i][j]=min(f[i][j],f[i][j-1]);
				if (s[i][j]!='a') f[i][j]+=1;
			}
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (f[i][j]<=k) f[i][j]=1; else f[i][j]=0;
	now.clear();
	int dis=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (f[i][j]) dis=max(dis,i+j-1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (f[i][j]&&i+j-1==dis) now.insert(make_pair(i,j));
	if (dis==0) now.insert(make_pair(1,1));
	if (dis==0) printf("%c",s[1][1]);
	for (int i=1;i<=dis;i++)
		printf("%c",'a');
	if (dis==0) dis=1;
	memset(vis,false,sizeof(vis));
	for (int i=dis+1;i<=2*n-1;i++)
	{
		int res='z'+1;
		for (set<pair<int,int> >::iterator it=now.begin();it!=now.end();it++)
		{
			int x=(*it).first,y=(*it).second;
			if (x+1<=n) res=min(res,(int)s[x+1][y]);
			if (y+1<=n) res=min(res,(int)s[x][y+1]);
			vis[x][y]=false;
		}
		printf("%c",res);
		now1.clear();
		for (set<pair<int,int> >::iterator it=now.begin();it!=now.end();it++)
		{
			int x=(*it).first,y=(*it).second;
			if (x+1<=n&&s[x+1][y]==res&&(!vis[x+1][y])) 
			{
				now1.insert(make_pair(x+1,y));
				vis[x+1][y]=true;
			}
			if (y+1<=n&&s[x][y+1]==res&&(!vis[x][y+1])) 
			{
				now1.insert(make_pair(x,y+1));
				vis[x][y+1]=true;
			}
		}
		now.clear();
		for (set<pair<int,int> >::iterator it=now1.begin();it!=now1.end();it++)
			now.insert((*it));
	}
	printf("\n");
	return 0;
}