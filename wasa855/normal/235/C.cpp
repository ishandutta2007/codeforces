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
#define N 2000005
char s[N],t[N];
int len[N],fa[N],ch[N][26];
int tx[N],a[N],siz[N],vis[N];
int las=1,cnt=1;
int ans,u,l,m,T;
void insert(int c)
{
	int p=las,np=las=++cnt;
	len[np]=len[p]+1; siz[np]=1;
	for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if(p==0) fa[np]=1;
	else
	{
		int q=ch[p][c];
		if(len[p]+1==len[q]) fa[np]=q;
		else
		{
			int nq=++cnt; len[nq]=len[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[nq]));
			fa[nq]=fa[q]; fa[q]=fa[np]=nq;
			for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		}
	}
}
void topo()
{
	for(int i=1;i<=cnt;i++) tx[len[i]]++;
	for(int i=1;i<=cnt;i++) vis[i]=-1;
	for(int i=1;i<=cnt;i++) tx[i]+=tx[i-1];
	for(int i=1;i<=cnt;i++) a[--tx[len[i]]]=i;
	for(int i=cnt;i>=1;i--)
	{
		int u=a[i];
		siz[fa[u]]+=siz[u];
	}
	siz[1]=0;
}
void add(int c)
{
	for(;u&&!ch[u][c];u=fa[u],l=len[u]);
	if(!u) u=1,l=0;
	if(ch[u][c]) l++,u=ch[u][c];
}
void del()
{
	if(l>m)
	{
		l--;
		if(l==len[fa[u]]) u=fa[u];
		if(!u) u=1;
	}
}
void calc()
{
	if(l==m)
	{
		if(vis[u]!=T)
		{
			vis[u]=T;
			ans+=siz[u];
		}
	}
}
signed main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++) insert(s[i]-'a');
	topo();
	// for(int i=1;i<=cnt;i++) printf("%d ",siz[i]); cout<<"\n";
	T=read();
	while(T--)
	{
		scanf("%s",t+1);
		m=strlen(t+1);
		ans=l=0; u=1;
		for(int i=1;i<=m;i++) add(t[i]-'a');
		// cout<<u<<endl;
		calc();
		for(int i=1;i<=m;i++)
		{
			// cout<<u<<" "<<l<<endl;
			// cout<<ans<<endl;
			add(t[i]-'a');
			// cout<<u<<" "<<l<<endl;
			del();
			// cout<<u<<" "<<l<<endl;
			calc();
		}
		printf("%d\n",ans);
	}
	return 0;
}