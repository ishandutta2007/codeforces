#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,k,d[N],q[N],b,e,fl;
map<string,int>mp;
char st[N];
string a[N];
vector<int>g[N];
void dfs(int x,int i,string r,int p)
{	
	if(i==k)
	{
		if(mp.find(r)==mp.end())
			return;
		int id=mp[r];
		if(id!=p)
			g[p].push_back(id),d[id]++;
		else
			fl=1;
		return;
	}
	dfs(x,i+1,r+a[x][i],p);
	dfs(x,i+1,r+"_",p);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",st);
		a[0]=st;
		mp[a[0]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%s",st);
		a[i]=st;
		int p;
		scanf("%d",&p);
		fl=0;
		dfs(i,0,"",p);
		if(!fl)
		{
			puts("NO");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		if(!d[i])
			q[e++]=i;
	while(b<e)
	{
		int u=q[b++];
		for(auto v:g[u])
		{
			d[v]--;
			if(!d[v])
				q[e++]=v;
		}
	}
	if(e!=n)
		puts("NO");
	else
	{
		puts("YES");
		for(int i=0;i<e;i++)
			printf("%d ",q[i]);
	}
	return 0;
}