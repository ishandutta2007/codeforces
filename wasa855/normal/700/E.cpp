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
#define N 400005
char s[N];
int ls[N*30],rs[N*30],rt[N],Cnt,n;
void insert(int &u,int l,int r,int p)
{
	u=++Cnt;
	if(l==r) return ;
	int mid=(l+r)/2;
	if(p<=mid) insert(ls[u],l,mid,p);
	else insert(rs[u],mid+1,r,p);
}
int merge(int u,int v,int l,int r)
{
	if(!u||!v) return u|v;
	int R=++Cnt;
	int mid=(l+r)/2;
	ls[R]=merge(ls[u],ls[v],l,mid);
	rs[R]=merge(rs[u],rs[v],mid+1,r);
	return R;
}
bool query(int u,int l,int r,int L,int R)
{
	if(!u) return 0;
	if(L<=l&&r<=R) return 1;
	int mid=(l+r)/2;
	if(L<=mid&&query(ls[u],l,mid,L,R)) return 1;
	if(R>mid&&query(rs[u],mid+1,r,L,R)) return 1;
	return 0;
}
int ch[N][26],fa[N],len[N],ed[N],cnt=1,las=1;
int tx[N],a[N],f[N],t[N];
void insert(int c)
{
	int p=las,np=las=++cnt;
	len[np]=len[p]+1;
	for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if(!p) fa[np]=1;
	else
	{
		int q=ch[p][c];
		if(len[p]+1==len[q]) fa[np]=q;
		else
		{
			int nq=++cnt; len[nq]=len[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			ed[nq]=ed[q];
			fa[nq]=fa[q],fa[q]=fa[np]=nq;
			for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		}
	}
}
signed main()
{
	int n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		insert(s[i]-'a');
		insert(rt[las],1,n,i);
		ed[las]=i;
	}
	for(int i=1;i<=cnt;i++) tx[len[i]]++;
	for(int i=1;i<=cnt;i++) tx[i]+=tx[i-1];
	for(int i=1;i<=cnt;i++) a[tx[len[i]]--]=i;
//	for(int i=1;i<=cnt;i++) printf("%d ",len[i]); cout<<"\n";
	for(int i=cnt;i>=2;i--)
	{
		int u=a[i];
		rt[fa[u]]=merge(rt[fa[u]],rt[u],1,n);
	}
	for(int i=2;i<=cnt;i++)
	{
		int u=a[i];
		if(fa[u]==1)
		{
			f[u]=1,t[u]=u;
			continue;
		}
		int x=t[fa[u]];
		if(query(rt[x],1,n,ed[u]-len[u]+len[x],ed[u]-1))
		{
			f[u]=f[x]+1,t[u]=u;
		}
		else
		{
			f[u]=f[x],t[u]=x;
		}
	}
	int ans=1;
	for(int i=1;i<=cnt;i++) if(f[i]>ans) ans=f[i];
	cout<<ans<<endl;
	return 0;
}