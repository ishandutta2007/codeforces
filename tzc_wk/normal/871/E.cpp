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
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
using namespace fastio;
const int MAXK=200;
const int MAXN=3e4;
int n,k,d[MAXK+5][MAXN+5],p[MAXK+5],fa[MAXN+5],anc[MAXK+5][MAXN+5];
void setfa(int x,int f){if(fa[x]&&fa[x]!=f) puts("-1"),exit(0);fa[x]=f;}
bool vis[MAXN+5];vector<pii> bel[MAXN+5];int f[MAXN+5];
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
bool merge(int x,int y){x=find(x);y=find(y);return (x==y)?0:(f[x]=y,1);}
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dep[MAXN+5];
void dfs(int x,int f,int *dep){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs(y,x,dep);
	}
}
int main(){
	read(n);read(k);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++) read(d[i][j]);
		vector<int> pt;
		for(int j=1;j<=n;j++) if(!d[i][j]) pt.pb(j);
		if(pt.size()!=1) return puts("-1"),0;
		p[i]=pt[0];
	} anc[1][0]=p[1];
	for(int i=2;i<=k;i++){
		vector<pii> vec;
		for(int j=1;j<=n;j++) if(d[i][j]+d[1][j]==d[1][p[i]])
			vec.pb(mp(d[1][j],j));
		sort(vec.begin(),vec.end());
		for(int j=0;j<vec.size();j++) if(vec[j].fi!=j) return puts("-1"),0;
		for(int j=1;j<vec.size();j++) setfa(vec[j].se,vec[j-1].se);
		for(int j=0;j<vec.size();j++) anc[i][j]=vec[j].se,vis[vec[j].se]=1;
	} vis[p[1]]=1;
	for(int i=1;i<=n;i++) if(!vis[i]){
		vector<pii> lca_s;
		for(int j=1;j<=k;j++){
			int dis=d[1][p[j]]+d[1][i]-d[j][i];
			if(dis&1) return puts("-1"),0;
			dis>>=1;lca_s.pb(mp(dis,anc[j][dis]));
		} sort(lca_s.begin(),lca_s.end());
		for(int j=1;j<lca_s.size();j++){
			if(lca_s[j].fi==lca_s[j-1].fi&&lca_s[j].se!=lca_s[j-1].se)
				return puts("-1"),0;
		} //printf("%d %d\n",i,lca_s.back().se);
		bel[lca_s.back().se].pb(mp(d[1][i],i));
	}
	for(int i=1;i<=n;i++) if(!bel[i].empty()){
		sort(bel[i].begin(),bel[i].end());
		int pre=d[1][i],prep=i;
		for(int l=0,r=0;l<bel[i].size();l=r){
			r=l;while(r<bel[i].size()&&bel[i][r].fi==bel[i][l].fi) ++r;
			if(bel[i][l].fi!=pre+1) return puts("-1"),0;
			for(int j=l;j<r;j++) setfa(bel[i][j].se,prep);
			pre=bel[i][l].fi;prep=bel[i][l].se;
		}
	}
//	for(int i=1;i<=n;i++) if(i!=p[1]) printf("%d %d\n",i,fa[i]);
	for(int i=1;i<=n;i++) if(i!=p[1]){
		if(!merge(i,fa[i])) return puts("-1"),0;
		adde(i,fa[i]);adde(fa[i],i);
	}
	for(int i=1;i<=k;i++){ 
		memset(dep,0,sizeof(dep));dfs(p[i],0,dep);
		for(int j=1;j<=n;j++) if(d[i][j]!=dep[j])
			return puts("-1"),0;
	}
	for(int i=1;i<=n;i++) if(i!=p[1]) printf("%d %d\n",fa[i],i);
	return 0;
}
/*
10 3
0 1 1 2 2 2 2 3 3 3
2 1 3 2 0 4 4 5 5 1
3 4 2 5 5 3 1 0 2 6
*/