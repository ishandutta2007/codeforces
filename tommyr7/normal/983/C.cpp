#include <bits/stdc++.h>
#define inf 20000007
using namespace std;
int f[2007][10][727];
bool vis[2007][10][727];
int que[1007][5],now[5],cnt=0;
int n,a[2007],b[2007];
pair<pair<int,int>,int> q[2007*10*720];
map<pair<pair<int,int>,pair<int,int> >,int> mp;
void dfs(int x,int r)
{
	if (x<=4)
	{
		for (int i=r;i<=9;i++)
		{
			now[x]=i;
			dfs(x+1,i);
		}
	} else
	{
		++cnt;
		for (int i=1;i<=4;i++)
			que[cnt][i]=now[i];
		mp[make_pair(make_pair(now[1],now[2]),make_pair(now[3],now[4]))]=cnt;
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	dfs(1,0);
	for (int i=0;i<=n;i++)
		for (int j=1;j<=9;j++)
			for (int k=1;k<=cnt;k++)
				f[i][j][k]=inf;
	f[0][1][mp[make_pair(make_pair(0,0),make_pair(0,0))]]=0;
	int lx=0,rx=1;
	q[1]=make_pair(make_pair(0,1),mp[make_pair(make_pair(0,0),make_pair(0,0))]);
	while (lx<rx)
	{
		int i=q[++lx].first.first;
		int pos=q[lx].first.second;
		int k=q[lx].second;
		if (pos>1&&f[i][pos-1][k]>f[i][pos][k]+1)
		{
			f[i][pos-1][k]=f[i][pos][k]+1;
			q[++rx]=make_pair(make_pair(i,pos-1),k);
		}
		if (pos<9&&f[i][pos+1][k]>f[i][pos][k]+1)
		{
			f[i][pos+1][k]=f[i][pos][k]+1;
			q[++rx]=make_pair(make_pair(i,pos+1),k);
		}
		if (pos==que[k][1])
		{
			int nowk=mp[make_pair(make_pair(0,que[k][2]),make_pair(que[k][3],que[k][4]))];
			if (f[i][pos][nowk]>f[i][pos][k]+1)
			{
				f[i][pos][nowk]=f[i][pos][k]+1;
				q[++rx]=make_pair(make_pair(i,pos),nowk);
			}
		}
		if (pos==que[k][2])
		{
			int nowk=mp[make_pair(make_pair(0,que[k][1]),make_pair(que[k][3],que[k][4]))];
			if (f[i][pos][nowk]>f[i][pos][k]+1)
			{
				f[i][pos][nowk]=f[i][pos][k]+1;
				q[++rx]=make_pair(make_pair(i,pos),nowk);
			}
		}
		if (pos==que[k][3])
		{
			int nowk=mp[make_pair(make_pair(0,que[k][1]),make_pair(que[k][2],que[k][4]))];
			if (f[i][pos][nowk]>f[i][pos][k]+1)
			{
				f[i][pos][nowk]=f[i][pos][k]+1;
				q[++rx]=make_pair(make_pair(i,pos),nowk);
			}
		}
		if (pos==que[k][4])
		{
			int nowk=mp[make_pair(make_pair(0,que[k][1]),make_pair(que[k][2],que[k][3]))];
			if (f[i][pos][nowk]>f[i][pos][k]+1)
			{
				f[i][pos][nowk]=f[i][pos][k]+1;
				q[++rx]=make_pair(make_pair(i,pos),nowk);
			}
		}
		if (i<n&&pos==a[i+1]&&que[k][1]==0)
		{
			now[1]=b[i+1];
			now[2]=que[k][2];
			now[3]=que[k][3];
			now[4]=que[k][4];
			sort(now+1,now+5);
			int nowk=mp[make_pair(make_pair(now[1],now[2]),make_pair(now[3],now[4]))];
			if (f[i+1][pos][nowk]>f[i][pos][k]+1)
			{
				f[i+1][pos][nowk]=f[i][pos][k]+1;
				q[++rx]=make_pair(make_pair(i+1,pos),nowk);
			}
		}
	}
	int ans=inf;
	for (int i=1;i<=9;i++)
		ans=min(ans,f[n][i][mp[make_pair(make_pair(0,0),make_pair(0,0))]]);
	printf("%d\n",ans);
	return 0;
}