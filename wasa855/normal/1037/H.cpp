#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 200005
char s[N],t[N];
int fa[N],len[N],ch[N][26],las=1,cnt=1;
vector<int> G[N];
int n,Q,pos[N],nd[N];
void insert(int c,int id)
{
	int p=las,np=las=++cnt;
	for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if(!p) fa[np]=1;
	else
	{
		int q=ch[p][c];
		if(len[p]+1==len[q]) fa[np]=q;
		else
		{
			int nq=++cnt; memcpy(ch[nq],ch[q],sizeof(ch[q]));
			len[nq]=len[p]+1,fa[nq]=fa[q],fa[q]=fa[np]=nq;
			for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		}
	}
	pos[np]=id;
}
int rt[N];
namespace SMT
{
	int t[N*40],ls[N*40],rs[N*40],cnt;
	void update(int &u,int las,int l,int r,int pos)
	{
		u=++cnt;
		// printf("%d %d %d %d\n",u,l,r,pos);
		t[u]=1,ls[u]=ls[las],rs[u]=rs[las];
		if(l==r) return ;
		int mid=(l+r)/2;
		if(pos<=mid) update(ls[u],ls[las],l,mid,pos);
		else update(rs[u],rs[las],mid+1,r,pos);
	}
	int merge(int u,int v,int l,int r)
	{
		if(!u||!v) return u|v;
		int nw=++cnt;
		t[nw]=t[u]|t[v];
		int mid=(l+r)/2;
		ls[nw]=merge(ls[u],ls[v],l,mid);
		rs[nw]=merge(rs[u],rs[v],mid+1,r);
		return nw;
	}
	int query(int u,int l,int r,int L,int R)
	{
		if(!u) return 0;
		if(L>R) return 0;
		if(L<=l&&r<=R) return t[u];
		int mid=(l+r)/2,ans=0;
		if(mid>=L) ans|=query(ls[u],l,mid,L,R);
		if(mid<R) ans|=query(rs[u],mid+1,r,L,R);
		return ans;
	}
};
using SMT::update;
using SMT::merge;
using SMT::query;
void dfs(int u)
{
	rt[u]=++SMT::cnt;
	if(pos[u]) update(rt[u],rt[u],1,n,pos[u]);
	for(int v:G[u]) dfs(v),rt[u]=merge(rt[u],rt[v],1,n);
}
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) insert(s[i]-'a',i);
	for(int i=2;i<=cnt;i++) G[fa[i]].pb(i);
	dfs(1);
	// for(int i=1;i<=cnt;i++) printf("%d %d\n",ch[i][0],ch[i][1]);
	cin>>Q;
	while(Q--)
	{
		int l=read(),r=read();
		scanf("%s",t+1); int m=strlen(t+1);
		nd[0]=1; for(int i=1;i<=m;i++) nd[i]=ch[nd[i-1]][t[i]-'a'];
		// for(int i=0;i<=m;i++) printf("%d%c",nd[i]," \n"[i==m]);
		t[m+1]='a'-1;
		int ok=0;
		auto chk=[&](int u,int len)
		{
			// printf("^^ %d %d %d\n",u,l+len-1,r);
			return query(rt[u],1,n,l+len-1,r);
		};
		for(int i=m;i>=0&&!ok;i--)
		{
			for(int j=t[i+1]-'a'+1;j<26&&!ok;j++)
			{
				if(!ch[nd[i]][j]) continue;
				int u=ch[nd[i]][j];
				if(chk(u,i+1))
				{
					ok=1;
					for(int k=1;k<=i;k++) putchar(t[k]);
					printf("%c\n",j+'a');
				}
			}
		}
		if(!ok) printf("-1\n");
	}
	return 0;
}