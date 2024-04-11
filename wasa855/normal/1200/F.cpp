#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 2520
#define ll long long
#define PA cout<<"Passed\n"
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
#define N 3005
int ans[N][N],w[N],dep[N][N],G[N][15],siz[N];
bool vis[N][N];
int Vis[N*N],cnt[N];
int dfs(int x,int y)
{
	vis[x][y]=1;
	if(ans[x][y]) return ans[x][y];
	Vis[dep[x][y]]=x;
	int tx=G[x][y%siz[x]],ty=add(y,w[tx]);
	if(vis[tx][ty])
	{
		if(ans[tx][ty]) return ans[x][y]=ans[tx][ty];
		int l=dep[tx][ty],r=dep[x][y];
		for(int i=l;i<=r;i++) cnt[Vis[i]]=0;
		for(int i=l;i<=r;i++) if(cnt[Vis[i]]==0) cnt[Vis[i]]=1,ans[x][y]++;
		return ans[x][y];
	}
	dep[tx][ty]=dep[x][y]+1;
	ans[x][y]=dfs(tx,ty);
	return ans[x][y];
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) w[i]=(read()%mod+mod)%mod;
//	PA;
	for(int i=1;i<=n;i++)
	{
		siz[i]=read();
		for(int j=0;j<siz[i];j++) G[i][j]=read();
	}
	int Q=read();
	while(Q--)
	{
		int x=read(),y=(read()%mod+mod)%mod;
		printf("%d\n",dfs(x,add(y,w[x])));
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}