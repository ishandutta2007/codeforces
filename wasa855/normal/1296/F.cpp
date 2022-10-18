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
#define N 5005
vector<pii> G[N];
int fa[N],fe[N],n,val[N];
struct Node
{
	int u,v,w;
};
Node a[N];
bool cmp(Node x,Node y)
{
	return x.w>y.w;
}
void dfs(int u,int Fa)
{
	fa[u]=Fa;
	for(pii v:G[u])
	{
		if(v.fir==Fa) continue;
		fe[v.fir]=v.sec;
		dfs(v.fir,u);
	}
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(mp(v,i)),G[v].pb(mp(u,i));
	}
	int m=read();
	for(int i=1;i<=m;i++)
	{
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		dfs(a[i].u,0);
		bool ok=0;
		int tmp=a[i].v;
		while(tmp!=a[i].u)
		{
			int e=fe[tmp];
			if(val[e]<=a[i].w) ok=1,val[e]=a[i].w;
			tmp=fa[tmp];
		}
		if(ok==0)
		{
			cout<<"-1\n";
			return 0;
		}
	}
	for(int i=1;i<n;i++) printf("%d ",max(val[i],1));
	cout<<"\n";
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}