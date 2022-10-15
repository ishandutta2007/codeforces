#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define fir first
#define sec second
#define mset(s,t) memset(s,t,sizeof(s))
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<20],*O=buf;
int getc(){
  return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
int read(){
  int x=0;
  char ch=getc();
  while(!isdigit(ch))ch=getc();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getc();
  return x;
}
const int N=50005;
int to[N<<1],nxt[N<<1];
int head[N],depth,tot,dfn[N],siz[N],rk[N];
void add(int u,int v) 
{
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
int tag[N],fa[N],dep[N];
void dfs(int u,int f) {
	dep[u]=dep[f]+1,fa[u]=f;dfn[u]=++depth;rk[depth]=u;siz[u]=1;
	for(register int i=head[u];i;i=nxt[i]){
		int v=to[i];
		dfs(v,u);siz[u]+=siz[v];
	}
}
ll sum,num;
int a[N],b[N],n,q,id;
int main() 
{
	n=read(),q=read();
	for(register int i=1;i<=n;i++)tag[i]=-1e9,a[i]=read();
	for(register int i=2;i<=n;i++){
		int _=read();
		add(_,i);
	}
	dfs(1,0);
  ll sum=num=0;
	for(int i=1;i<=n;i++)b[i]=a[i];
	for(int i=1;i<=n;i++)a[dfn[i]]=b[i];
	for(int i=1;i<=n;i++)b[i]=dep[i];
	for(int i=1;i<=n;i++)dep[dfn[i]]=b[i];
	for(int i=1;i<=n;i++)b[i]=tag[i];
	for(int i=1;i<=n;i++)tag[dfn[i]]=b[i];	
	for(register int i=1;i<=q;i++){
		int u=read();
		int r=dfn[u]+siz[u]-1;
		sum=num=0;int x;
		for(register int j=dfn[u];j<=r;j++)
			if(tag[j]<=i){
				tag[j]=i+a[j];
				sum+=dep[j];num++;
			}
		printf("%lld %lld\n",sum-num*dep[dfn[u]],num);
	}
	return 0;
}