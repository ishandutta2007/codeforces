#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int h[N],bit[N*2],f[N],g[N],out[N],can[N],can2[N],cnt,n,m,lis,must;
map<int,int>mp;
vector<int>all,fe[N],ge[N];
vector<pair<int,int>>e[N];
int sum(int i)
{
	int s=0;
	while(i)
	{
		s=max(s,bit[i]);
		i-=i&-i;
	}
	return s;
}
void update(int i,int x)
{
	while(i<=all.size())
	{
		bit[i]=max(bit[i],x);
		i+=i&-i;	
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		all.push_back(h[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		e[a].push_back(make_pair(b,i));
		all.push_back(b);
	}
	sort(all.begin(),all.end());
	mp[all[0]]=++cnt;
	for(int i=1;i<all.size();i++)
		if(all[i]!=all[i-1])
			mp[all[i]]=++cnt;
	for(int i=1;i<=n;i++)
	{
		h[i]=mp[h[i]];
		for(int j=0;j<e[i].size();j++)
			e[i][j].first=mp[e[i][j].first];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<e[i].size();j++)
			fe[i].push_back(sum(e[i][j].first-1)+1);
		int tmp=sum(h[i]-1);
		f[i]=tmp+1;
		update(h[i],f[i]);
	}
	memset(bit,0,sizeof(bit));
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<e[i].size();j++)
			ge[i].push_back(sum(cnt+1-e[i][j].first-1)+1);
		int tmp=sum(cnt+1-h[i]-1);
		g[i]=tmp+1;
		update(cnt+1-h[i],g[i]);
	}
	for(int i=1;i<=n;i++)
		lis=max(lis,f[i]+g[i]-1);
	memset(can2,-1,sizeof(can2));
	for(int i=1;i<=n;i++)
	{
		if(f[i]+g[i]-1==lis)
		{
			if(can2[f[i]]==-1)
				can2[f[i]]=i;
			else
				can2[f[i]]=-2;
		} 
	}
	for(int i=1;i<=n;i++)
		if(can2[i]>=0)
			can[can2[i]]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<e[i].size();j++)
		{
			if(can[i])
				out[e[i][j].second]=max(lis-1,fe[i][j]+ge[i][j]-1);
			else
				out[e[i][j].second]=max(lis,fe[i][j]+ge[i][j]-1);
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",out[i]);
	return 0;
}