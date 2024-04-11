#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define lowbit(i) i&-i
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
const int N=400005,K=19;
int in[N],c[N],fa[N],out[N],top[N],wson[N],dp[N][K],dep[N],sz[N];
int n,m,ti;
ll ans[N],sz2[N],dq;
vector<int> v[N];
vector<PI> co[N];
bool vis[N];
inline ll sqr(ll x){return x*x;}
void dfs1(int p,int f){
	dp[p][0]=fa[p]=f; sz[p]=1; dep[p]=dep[f]+1;
	for(auto i:v[p])if(i!=f){dfs1(i,p); sz[p]+=sz[i]; if(sz[i]>sz[wson[p]])wson[p]=i;}
}
void dfs2(int p){
	in[p]=++ti; top[p]=wson[fa[p]]==p?top[fa[p]]:p;
	if(wson[p])dfs2(wson[p]);
	for(auto i:v[p])if(i!=fa[p]&&i!=wson[p])dfs2(i);
	out[p]=ti;
}
struct BIT{
	int c[N];
	inline int qiu(int pos){
		if(!pos)return 0; int ans=0; 
		for(int i=pos;i<N;i+=lowbit(i))ans+=c[i];
		return ans;
	}
	inline void add(int pos,int de){
		for(int i=pos;i;i-=lowbit(i))c[i]+=de;
	}
	void add(int l,int r,int de){
		add(l-1,-de); add(r,de);
	}
}Sz,ef;
int getsz(int x){
	return Sz.qiu(in[x]);
}
ll getsz2(int x){
	ll ans=sz2[x];
	if(wson[x]&&vis[wson[x]]==0)ans+=sqr(getsz(wson[x]));
	return ans;
}
int get(int x){
	Rep(i,K-1,0)if(dp[x][i]&&ef.qiu(in[fa[x]])==ef.qiu(in[dp[fa[x]][i]]))x=dp[x][i];
	return x;
}
void update(int x,int y,int de){
	while(x&&dep[x]>=dep[y]){
		int t=top[x]; if(dep[t]<dep[y])t=y;
		//cerr<<x<<" "<<wson[fa[t]]<< " "<<t<<" "<<top[5]<<endl;
		if(fa[t]&&vis[t]==0&&wson[fa[t]]!=t){//cerr<<top[x]<< " "<<x<<" "<<y<<" "<<t<<endl;
			int zs=Sz.qiu(in[t]);
			sz2[fa[t]]-=sqr(zs);
			sz2[fa[t]]+=sqr(zs+de);
		}
		Sz.add(in[t],in[x],de); x=fa[t];
	}
}
void cao(int x){
	int t,jb,jj=getsz(x);
	if(vis[fa[x]])t=x; else t=get(fa[x]);
	update(fa[x],fa[t],(vis[x]?1:-1)*jj);
	if(wson[fa[x]]!=x){sz2[fa[x]]+=(vis[x]?1:-1)*sqr(jj); }
	if(vis[fa[x]])jb=0; else {jb=getsz(t); if(vis[x])jb-=jj;}
	//cerr<<x<<" fjzzq "<<t<<" "<<jb+getsz(x)<<" "<<jb<<" "<<getsz2(x)<<" "<<sz2[x]<<" "<<sz2[3]<<endl;
	dq+=(vis[x]?1:-1)*(sqr(jb+jj)-sqr(jb)-getsz2(x));
	ef.add(in[x],out[x],vis[x]?-1:1);
	vis[x]^=1;
	//cerr<<dq<<endl;
}
int main(){
	vis[0]=1;
	n=read(),m=read();
	For(i,1,n)co[c[i]=read()].pb(mp(i,0));
	For(i,2,n){
		int s=read(),t=read();
		v[s].pb(t); v[t].pb(s);
	}
	dfs1(1,0); dfs2(1);
	For(i,1,K-1)For(j,1,n)dp[j][i]=dp[dp[j][i-1]][i-1];
	For(i,1,m){
		int u=read();
		co[c[u]].pb(mp(u,i)); co[c[u]=read()].pb(mp(u,i));
	}
	For(i,1,n)co[c[i]].pb(mp(i,m+1)); 
	dq=(ll)n*n; For(i,1,n){Sz.add(in[i],in[i],sz[i]); for(auto j:v[i])if(j!=wson[i]&&j!=fa[i])sz2[i]+=sqr(sz[j]);}
	ans[0]=dq*n;
	//For(i,1,n)wri(getsz2(i)); puts("");
	//static int q[N]; For(i,1,n)q[i]=i; For(i,1,4000){random_shuffle(&q[1],&q[n+1]); For(j,1,n)cao(j);}
	//For(i,1,n)wri(getsz2(i)); puts("");
	For(i,1,n){
		for(auto j:co[i]){ll dd=dq; cao(j.fi);  ans[j.se]+=dq-dd;}
		assert(dq==(ll)n*n);
	}
	//return 0;
	For(i,0,m){
		if(i)ans[i]+=ans[i-1];
		writeln((ll)n*n*n-ans[i]);
	}
}
/*
10 0
3 6 6 9 7 6 4 7 8 9
2 4
9 2
6 4
1 9
3 1
8 1
5 8
10 6
7 4
2 8
10 1
6 8
3 5
7 10
2 4
10 6
5 1
4 8
1 10
7 6
1 1
7 1
6 8
7 7
6 1
7 4
7 1
9 5
10 1
3 4
3 5
5 10
8 2
7 4
5 6
3 3
6 7
1 7
3 10
5 4
9 3
2 10
5 9
9 10
3 1
7 9
5 5
6 8
1 1
1 5
4 5
10 10
5 8
2 9
9 4
1 2
4 3
10 9
4 8
7 1
9 9
2 3
9 1
5 6
6 5
4 9
9 8
5 2
4 2
10 8
5 1
9 8
2 6
10 1
4 1
5 4
10 10
8 8
9 1
9 7
7 9
7 4
8 10
6 2
1 2
5 2
6 2
7 9
6 3
2 4
4 10
5 9
*/