#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 1005
vector<int> G[N];
int siz[N];
void dfs(int u,int fa)
{
	siz[u]=1;
	int ss=G[u].size();
	for(int i=0;i<ss;i++)
	{
		int to=G[u][i];
		if(to==fa) continue;
		dfs(to,u);
		siz[u]+=siz[to];
	}
}
void print1(int u,int fa)
{
	int sum=0,ss=G[u].size();
	for(int i=0;i<ss;i++)
	{
		int to=G[u][i];
		if(to==fa) continue;
		print1(to,u);
		printf("%d %d %d\n",u,to,sum+1);
		sum+=siz[to];
	}
}
void print2(int u,int fa,int x)
{
	int sum=0,ss=G[u].size();
	for(int i=0;i<ss;i++)
	{
		int to=G[u][i];
		if(to==fa) continue;
		print2(to,u,x);
		printf("%d %d %d\n",u,to,(sum+1)*x);
		sum+=siz[to];
	}
}
vector<pii> a;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,0);
		a.clear();
		int ss=G[i].size();
		for(int j=0;j<ss;j++)
		{
			a.pb(mp(siz[G[i][j]],G[i][j]));
		}
		sort(a.begin(),a.end());
		int sum=0,st=a.size();
		for(int j=st-1;j>=0;j--)
		{
			sum+=a[j].first;
			if((sum+1)*(n-sum)-1>=2*n*n/9)
			{
				int s=0;
				for(int k=0;k<j;k++)
				{
					print2(a[k].second,i,sum+1);
					printf("%d %d %d\n",i,a[k].second,(s+1)*(sum+1));
					s+=a[k].first;
				}
				s=0;
				for(int k=j;k<st;k++)
				{
					print1(a[k].second,i);
					printf("%d %d %d\n",i,a[k].second,(s+1));
					s+=a[k].first;
				}
				return 0;
			}
		}
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}