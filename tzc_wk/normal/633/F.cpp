#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
int n,a[MAXN+5];
vector<int> g[MAXN+5];
vector<pair<ll,ll> > pre[MAXN+5];
vector<pair<ll,ll> > suf[MAXN+5];
pair<ll,ll> out[MAXN+5],dp[MAXN+5];
pair<ll,ll> merge(pair<ll,ll> x,ll y){
	ll a[3]={0};a[0]=x.fi;a[1]=x.se;a[2]=y;
	sort(a,a+3);reverse(a,a+3);return mp(a[0],a[1]);
}
void dfs1(int x=1,int f=0){
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];if(y==f) continue;
		dfs1(y,x);dp[x]=merge(dp[x],dp[y].fi+a[y]);
	}
}
void dfs2(int x=1,int f=0){
	pre[x].resize(g[x].size()+2);
	suf[x].resize(g[x].size()+2);
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y==f) pre[x][i+1]=merge(pre[x][i],out[x].fi+a[f]);
		else pre[x][i+1]=merge(pre[x][i],dp[y].fi+a[y]);
	}
	for(int i=(int)g[x].size()-1;~i;i--){
		int y=g[x][i];
		if(y==f) suf[x][i+1]=merge(suf[x][i+2],out[x].fi+a[f]);
		else suf[x][i+1]=merge(suf[x][i+2],dp[y].fi+a[y]);
	}
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];if(y==f) continue;
		ll a[4]={0};
		a[0]=pre[x][i].fi;a[1]=pre[x][i].se;
		a[2]=suf[x][i+2].fi;a[3]=suf[x][i+2].se;
		sort(a,a+4);reverse(a,a+4);out[y]=mp(a[0],a[1]);
		dfs2(y,x);
	}
}
ll mx[MAXN+5],ans=0;
void dfs3(int x=1,int f=0){
	mx[x]=dp[x].fi+dp[x].se+a[x];
	ll mx1=0,mx2=0;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];if(y==f) continue;
		dfs3(y,x);chkmax(mx[x],mx[y]);
		if(mx[y]>mx1) mx2=mx1,mx1=mx[y];
		else if(mx[y]>mx2) mx2=mx[y];
	}
	if(mx2) chkmax(ans,mx1+mx2);
}
ll mxx[MAXN+5];
void dfs4(int x=1,int f=0){
	if(x!=1) chkmax(ans,dp[x].fi+dp[x].se+a[x]+mxx[x]);
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];if(y==f) continue;
		mxx[y]=max(mxx[x],out[y].fi+out[y].se+a[x]);dfs4(y,x);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g[u].pb(v),g[v].pb(u);
	dfs1();dfs2();dfs3();dfs4();printf("%lld\n",ans);
	return 0;
}
/*1
9
1 2 3 4 5 6 7 8 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
*/
/*2
2
20 10
1 2
*/
/*
5
1 5 4 2 3
1 2
2 3
2 4
1 5
*/