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
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
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
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e3;
const double EPS=1e-7;
const int MOD=1e9+7;
const int INV2=5e8+4;
int n,m,q,dp[MAXN+5][MAXN+5];ll mx[MAXN+5];
struct edge{int u,v,w;} e[MAXN+5];
vector<pii> g[MAXN+5];
struct line{
	int k,b;
	bool operator <(const line &rhs){
		if(k!=rhs.k) return k<rhs.k;
		return b<rhs.b;
	}
} l[MAXN+5];
double inter(line a,line b){return 1.0*(a.b-b.b)/(b.k-a.k);}
int stk[MAXN+5],tp=0;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		g[e[i].u].pb(mp(e[i].v,e[i].w));
		g[e[i].v].pb(mp(e[i].u,e[i].w));
	} memset(dp,192,sizeof(dp));dp[0][1]=0;
	for(int i=0;i<m;i++) for(int j=1;j<=n;j++){
		for(pii p:g[j]) chkmax(dp[i+1][p.fi],dp[i][j]+p.se);
	} int ans=0;memset(mx,192,sizeof(mx));
	for(int i=1;i<=m;i++){
		int mxs=0;
		for(int j=1;j<=n;j++) chkmax(mxs,dp[i][j]);
		ans=(0ll+ans+mxs)%MOD;
		for(int j=1;j<=m;j++){
			chkmax(mx[j],dp[i][e[j].u]-1ll*e[j].w*i);
			chkmax(mx[j],dp[i][e[j].v]-1ll*e[j].w*i);
		}
	} int p=0;
	for(int j=1;j<=m;j++) if(mx[j]>-0x3f3f3f3f) l[++p].k=e[j].w,l[p].b=mx[j];
	sort(l+1,l+p+1);
	for(int i=1;i<=p;i++){
		if(l[i+1].k==l[i].k) continue;
		while(tp>1){
			double it1=inter(l[stk[tp]],l[stk[tp-1]]);
			double it2=inter(l[stk[tp]],l[i]);
			if(it2>it1) break;tp--;
		} stk[++tp]=i;
	}
	for(int i=1;i<=tp;i++){
		double lft=((i==1)?m:inter(l[stk[i]],l[stk[i-1]]));
		double rit=((i==tp)?q:inter(l[stk[i]],l[stk[i+1]]));
		int L=(int)ceil(lft+EPS),R=floor(rit);
		chkmax(L,m+1);chkmin(R,q);
		if(L>R) continue;
//		printf("%d %d\n",L,R);
//		printf("%d %d\n",l[stk[i]].k,l[stk[i]].b);
		int tl=(l[stk[i]].b+1ll*L*l[stk[i]].k)%MOD;
		int tr=(l[stk[i]].b+1ll*R*l[stk[i]].k)%MOD;
		ans=(ans+1ll*(tl+tr)*(R-L+1)%MOD*INV2)%MOD;
	} printf("%d\n",ans);
	return 0;
}