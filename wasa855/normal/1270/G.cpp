#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 1000005
vector<int> G[N];
int a[N];
int vis[N],fa[N];
int ans;
void adde(int u,int v)
{
	G[u].pb(v);
}
void dfs(int u)
{
//	printf("%d \n",u);
	if(ans!=0) return ;
	vis[u]=1;
	for(int v:G[u])
	{
//		if(v==fa[u]) continue;
		if(vis[v]) ans=u;
		dfs(v);
	}
}
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) adde(i,i-a[i]);
	for(int i=1;i<=n;i++) fa[i]=i-a[i];
	for(int i=1;i<=n;i++) vis[i]=0;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			printf("1\n%d\n",i);
			return ;
		}
	}
	dfs(1);
	vector<int> v;
	v.pb(ans);
	int tmp=fa[ans];
	while(tmp!=ans)
	{
		v.pb(tmp),tmp=fa[tmp];
	}
	cout<<v.size()<<endl;
	for(int i:v) printf("%d ",i); cout<<"\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}