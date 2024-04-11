#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=200005,M=N<<1,K=18;
vector<int> v[N];
int cnt,ti,color,ne=1,top;
int dp[N][K],q[N],col[N],in[N],out[N],dfn[N],low[N],to[N],son[N],ed[M],nxt[M];
void GG(){
	puts("No"); exit(0);
}
void ae(int a,int b){
	nxt[++ne]=son[a]; son[a]=ne; ed[ne]=b;
}
struct data{
	int s[N];
	void add(int a,int b){
		s[a]++; s[b]--;
	}
	void solve(int p,int fa){
		col[p]=1;
		for(auto i:v[p])if(i!=fa){solve(i,p); s[p]+=s[i];}
	}
}T[2];
void dfs(int p,int fa){
	q[++top]=p; dfn[p]=low[p]=++ti;
	for(int i=son[p];i;i=nxt[i])if(i!=(fa^1)){
		int v=ed[i];
		if(!dfn[v]){
			dfs(v,i); low[p]=min(low[p],low[v]);
		}else low[p]=min(low[p],dfn[v]);
	}
	if(dfn[p]==low[p]){
		cnt++;
		while(1){
			to[q[top]]=cnt;
			if(q[top--]==p)break;
		}
	}
}
void ddd(int p,int fa){
	col[p]=color; dp[p][0]=fa; in[p]=++ti;
	for(auto i:v[p])if(i!=fa)ddd(i,p);
	out[p]=ti;
}
bool zx(int a,int b){
	return in[a]<=in[b]&&out[a]>=out[b];
}
int get(int a,int b){
	if(zx(a,b))return a;
	Rep(i,K-1,0)if(dp[a][i]&&!zx(dp[a][i],b))a=dp[a][i];
	return dp[a][0];
}
int main(){
	int n=read(),m=read(),q=read();
	For(i,1,m){
		int s=read(),t=read();
		ae(s,t); ae(t,s);
	}
	For(i,1,n)if(!dfn[i])dfs(i,0);
	For(i,1,n)for(int j=son[i];j;j=nxt[j])if(to[i]!=to[ed[j]])v[to[i]].pb(to[ed[j]]);
	For(i,1,cnt)if(!col[i]){
		color++;
		ddd(i,0);
	}
	For(i,1,K-1)For(j,1,cnt)dp[j][i]=dp[dp[j][i-1]][i-1];
	while(q--){
		int u=to[read()],v=to[read()];
		if(col[u]!=col[v])GG();
		int lca=get(u,v);
		T[0].add(u,lca);
		T[1].add(v,lca);
	}
	For(i,0,1){mem(col); For(j,1,n)if(!col[j])T[i].solve(j,0);}
	For(i,1,n)if(T[0].s[i]&&T[1].s[i])GG();
	puts("Yes");
}