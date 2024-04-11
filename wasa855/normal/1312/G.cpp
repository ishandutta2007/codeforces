#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
inline char rdchar()
{
	char ch=getchar();
	while(!((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))) ch=getchar();
	return ch;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 1000005
int ch[N][26];
int dep[N],f[N],dfn[N],n,cnt,id[N];
bool s[N];
void dfs(int u,int fa,int cur,int las)
{
	if(u!=0)
	{
		if(s[u]) dfn[u]=++cnt;
		else dfn[u]=cnt+1;
		dep[u]=dep[fa]+1;
		if(s[u]) f[u]=min(dep[u]-dep[las]+f[las],dfn[u]-cur);
		else f[u]=f[las]+dep[u]-dep[las];
		if(dfn[u]-f[u]-1>cur) cur=dfn[u]-f[u]-1;
		if(s[u]) las=u;
	}
	// printf("%d %d %d %d %d %d\n",u,cur,las,dep[u],f[u],dfn[u]);
	for(int i=0;i<26;i++)
	{
		if(ch[u][i]) dfs(ch[u][i],u,cur,las);
	}
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int u=read();
		char v=rdchar();
		ch[u][v-'a']=i;
	}
	int Q=read();
	for(int i=1;i<=Q;i++)
	{
		id[i]=read();
		s[id[i]]=1;
	}
	dfs(0,0,0,0);
	for(int i =1;i<=Q;i++)
	{
		printf("%d ",f[id[i]]);
	}
	return 0;
}