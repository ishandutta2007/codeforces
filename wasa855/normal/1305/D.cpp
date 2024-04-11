#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 1005
bool vis[N],inq[N];
int query(int x,int y)
{
	vis[x]=vis[y]=1;
	printf("? %d %d\n",x,y);
	fflush(stdout);
	return read();
}
vector<int> G[N];
int n,dgr[N],fa[N];
void dfs(int u,int Fa)
{
	fa[u]=Fa;
	for(int v:G[u])
	{
		if(v!=Fa) dfs(v,u);
	}
}
signed main()
{
#ifdef __LOCAL__
//	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
		dgr[u]++,dgr[v]++;
	}
	int rt=0;
	for(int i=1;i<=n;i++) if(dgr[i]!=1) rt=i;
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(dgr[i]==1) q.push(i),inq[i]=1;
	}
	while(1)
	{
		dfs(rt,0);
		while(q.size()>=2)
		{
			int u=q.front(); q.pop();
			int v=q.front(); q.pop();
			int x=query(u,v);
			if(x==u||x==v)
			{
				printf("! %d\n",x);
				fflush(stdout);
				return 0;
			}
			int a=fa[u],b=fa[v];
			dgr[a]--,dgr[b]--;
			if(dgr[a]==1)
			{
				q.push(a); inq[a]=1;
				if(a==rt) goto ed;
			}
			if(dgr[b]==1&&a!=b)
			{
				q.push(b); inq[b]=1;
				if(b==rt) goto ed;
			}
		}
		ed:;
		vector<int> v;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			if(dgr[i]>1) cnt++,rt=i;
			if(!inq[i]&&dgr[i]==1)
			{
				q.push(i),inq[i]=1;
			}
			v.pb(i);
		}
		if(v.size()==1)
		{
			printf("! %d\n",v[0]);
			fflush(stdout);
			return 0;
		}
		if(v.size()==2)
		{
			printf("! %d\n",query(v[0],v[1]));
			fflush(stdout);
			return 0;
		}
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}