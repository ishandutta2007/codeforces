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
const int MAXN=2e5;
const ll INFll=0x3f3f3f3f3f3f3f3fll;
int n,m,B,G,N,M;
vector<int> b[MAXN+5],g[MAXN+5];
int gcd(int x,int y){return (!y)?x:gcd(y,x%y);}
void exgcd(int x,int y,int &a,int &b){
	if(!y) return a=1,b=0,void();exgcd(y,x%y,a,b);
	int tmp=a;a=b;b=tmp-(x/y)*b;
}
int getinv(int a,int mod){
	int x,y;exgcd(a,mod,x,y);
	return (x+mod)%mod;
}
ll solve(vector<int> &b,vector<int> &g,int n,int m){
	map<int,bool> in;map<int,int> dis;set<int> pos;
	for(int x:b){in[x]=1;pos.insert(x);dis[x]=x;}
	for(int x:g){
		pos.insert(x%n);
		if(!dis.count(x%n)) dis[x%n]=x%n;
		else chkmin(dis[x%n],x%n);
	} int iv=getinv(m,n);
	vector<pair<int,pii> > vec;int pos0=(*pos.begin());
	for(int p:pos) vec.pb(mp(1ll*(p-pos0)*iv%n,mp(dis[p],in[p])));
	vec.pb(mp(n,mp(0,1)));sort(vec.begin(),vec.end());ll mx=-1;
//	for(int i=0;i<vec.size();i++) printf("%d %d %d\n",vec[i].fi,vec[i].se.fi,vec[i].se.se);
//	printf("\n");
	for(int i=1;i<vec.size();i++) if(!vec[i-1].se.se||vec[i].fi!=vec[i-1].fi+1)
		chkmax(mx,1ll*(vec[i].fi-vec[i-1].fi-1)*m+vec[i-1].se.fi);
//	printf("%d\n",mx);
	return mx;
}
int main(){
	scanf("%d%d",&n,&m);int d=gcd(n,m);N=n/d;M=m/d;
	if(d>MAXN) return puts("-1"),0;
	scanf("%d",&B);for(int i=1,x;i<=B;i++) scanf("%d",&x),b[x%d].pb(x/d);
	scanf("%d",&G);for(int i=1,x;i<=G;i++) scanf("%d",&x),g[x%d].pb(x/d);
	for(int i=0;i<d;i++) if(b[i].empty()&&g[i].empty()) return puts("-1"),0;
	ll res=0;
	for(int i=0;i<d;i++){
		chkmax(res,1ll*d*solve(b[i],g[i],N,M)+i);
		chkmax(res,1ll*d*solve(g[i],b[i],M,N)+i);
	} printf("%lld\n",res);
	return 0;
}