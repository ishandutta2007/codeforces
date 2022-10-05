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
const int MAXN=1e3;
const int LOG_N=30;
const int MOD=998244353;
int n,m,a[MAXN+5];vector<pii> vc[MAXN+5];
struct mat{
	int n,m,a[65][65];
	mat(){memset(a,0,sizeof(a));}
	mat operator *(const mat &rhs){
		mat res;res.n=n;res.m=rhs.m;
		for(int i=0;i<n;i++) for(int j=0;j<rhs.m;j++) for(int k=0;k<m;k++)
			res.a[i][j]=(res.a[i][j]+1ll*a[i][k]*rhs.a[k][j])%MOD;
		return res;
	}
	void print(){
		for(int i=0;i<=63;i++) for(int j=0;j<=63;j++)
			printf("%d%c",a[i][j]," \n"[j==63]);
	}
} I,pw[LOG_N+2],cm[4];
int can[4][4],dp[MAXN+5][5];
int main(){
	scanf("%d",&n);//!!!
	I.n=I.m=64;for(int i=0;i<=63;i++) I.a[i][i]=1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1,x,y,c;i<=m;i++) scanf("%d%d%d",&x,&y,&c),vc[x].pb(mp(y,c));
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) scanf("%d",&can[i][j]);
	pw[0].n=pw[0].m=64;for(int i=0;i<3;i++) cm[i].n=cm[i].m=64;
	for(int i=0;i<64;i++) for(int j=0;j<3;j++){
		int c1=i>>4,c2=i>>2&3,c3=i&3;
		static bool vis[4];memset(vis,0,sizeof(vis));
		if(can[j][0]) vis[c1]=1;
		if(can[j][1]) vis[c2]=1;
		if(can[j][2]) vis[c3]=1;
		int sg=0;while(vis[sg]) sg++;
		int nmsk=(c1<<2)|c2|(sg<<4);//printf("%d %d %d\n",i,j,nmsk);
		pw[0].a[i][nmsk]++;cm[j].a[i][nmsk]++;
	} for(int i=1;i<=LOG_N;i++) pw[i]=pw[i-1]*pw[i-1];
//	pw[0].print();
//	puts("0");cm[0].print();cm[1].print();cm[2].print();
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		mat cur;cur.n=1;cur.m=64;cur.a[0][63]=1;int pre=1;
		sort(vc[i].begin(),vc[i].end());
		for(int j=0;j<vc[i].size();j++){
			int p=vc[i][j].fi,c=vc[i][j].se;
			int len=p-pre;//printf("len=%d\n",len);
			for(int k=0;k<LOG_N;k++) if(len>>k&1) cur=cur*pw[k];
			pre=p+1;cur=cur*cm[c-1];
		} int len=a[i]+1-pre;//printf("len=%d\n",len);
		for(int k=0;k<LOG_N;k++) if(len>>k&1) cur=cur*pw[k];
//		for(int k=0;k<64;k++) printf("%d%c",cur.a[0][k]," \n"[k==63]);
		for(int j=0;j<4;j++) for(int k=0;k<64;k++){
			dp[i][j]=(dp[i][j]+1ll*dp[i-1][j^(k>>4)]*cur.a[0][k])%MOD;
		}
//		for(int j=0;j<4;j++) printf("%d %d %d\n",i,j,dp[i][j]);
	} printf("%d\n",dp[n][0]);
	return 0;
}