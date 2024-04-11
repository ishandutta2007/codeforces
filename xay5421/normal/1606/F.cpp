// author: xay5421
// created: Fri Oct 29 22:44:41 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline char getc(){static char buf[1<<20],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getc()))f^=!(c^45);x=(c&15);while(isdigit(c=getc()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
template<class T>void umax(T&x,const T&y){if(x<y)x=y;}
const int N=200005,B=1500,S=N/B+3;
int n,K,Q,f[N],g[N],ans[N],dp[N][S];
vector<int>e[N];
vector<pair<int,int> >qs[N],QS[N];
int ord[N],fa[N],ind;
void dfs0(int k1,int k2){
	ord[++ind]=k1,fa[k1]=k2;
	for(auto x:e[k1])if(x!=k2)dfs0(x,k1);
}
void dfs2(int k1,int k2){
	dp[k1][0]=0;
	for(auto x:e[k1])if(x!=k2){
		dfs2(x,k1);
		per(a,S-1,0)per(b,S-1-a,0)umax(dp[k1][a+b],dp[k1][a]+dp[x][b]);
	}
	for(auto x:QS[k1]){
		ans[x.second]=SZ(e[k1])-(k1!=1);
		rep(a,1,S-1){
			umax(ans[x.second],dp[k1][a]-a*x.first);
		}
	}
	per(i,S-2,0)dp[k1][i+1]=dp[k1][i];
	dp[k1][0]=1;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	memset(dp,192,sizeof(dp));
	rd(n);
	rep(i,2,n){
		int k1,k2;
		rd(k1),rd(k2);
		e[k1].pb(k2),e[k2].pb(k1);
	}
	rd(Q);
	rep(i,1,Q){
		int v,k;
		rd(v),rd(k);
		if(k<=B)qs[k].eb(v,i);
		else QS[v].eb(k,i);
	}
	dfs0(1,0);
	rep(k,0,B)if(SZ(qs[k])){
		K=k;
		memset(f,0,sizeof(f[0])*(n+1));
		memset(g,0,sizeof(g[0])*(n+1));
		per(i,n,1){
			f[ord[i]]=max(g[ord[i]]-K,1);
			g[fa[ord[i]]]+=f[ord[i]];
		}
		for(auto x:qs[k]){
			ans[x.second]=g[x.first];
		}
	}
	dfs2(1,0);
	rep(i,1,Q)pt(ans[i],'\n');
	return 0;
}