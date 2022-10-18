#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int a[N],d[N];
vector<int> G[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(i-a[i]>=1&&((a[i]&1)==(a[i-a[i]]&1))) G[i-a[i]].pb(i);
		if(i+a[i]<=n&&((a[i]&1)==(a[i+a[i]]&1))) G[i+a[i]].pb(i);
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		d[i]=-1;
		if(i-a[i]>=1&&((a[i]&1)!=(a[i-a[i]]&1))) d[i]=1;
		if(i+a[i]<=n&&((a[i]&1)!=(a[i+a[i]]&1))) d[i]=1;
		if(d[i]==1) q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(d[v]!=-1) continue;
			d[v]=d[u]+1;
			q.push(v);
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",d[i]);
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}