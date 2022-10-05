//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
//#pragma GCC optimize("move-loop-invariants")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC optimize("branch-target-load-optimize")
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
const int MAXN=3e5;
const int INF=0x3f3f3f3f;
int n,m,k,f[MAXN+5],sum[MAXN+5];
bool vis[MAXN*2+5],ban[MAXN*2+5],flg=0;int siz=0,cnt[MAXN+5];
int hd[MAXN*2+5],nxt[MAXN*2+5],to[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int find(int x){
	if(!f[x]) return x;int fx=f[x],ff=find(f[x]);
	sum[x]+=sum[fx];return f[x]=ff;
}
int getsum(int x){find(x);return sum[x];}
void merge(int x,int y,int d){
//	printf("merge %d %d %d\n",x,y,d);
	int dx=0;dx-=getsum(x);x=find(x);
	int dy=d;dy-=getsum(y);y=find(y);
	if(x==y) return;//printf("%d %d %d %d\n",x,y,dx,dy);
	f[y]=x;sum[y]=dy-dx;
}
void dfs(int x){
	if(vis[x]) return;flg|=ban[x];siz+=(x<=k);vis[x]=1;
	for(int e=hd[x];e;e=nxt[e]) dfs(to[e]);
}
/*polynomial template below*/
const int MAXP=1<<20;
const int pr=3;
const int ipr=332748118;
const int MOD=998244353;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int rev[MAXP+5];set<int> in[MAXN+5],out[MAXN+5];
void NTT(vector<int> &a,int len,int type){
	int lg=31-__builtin_clz(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1);
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		int W=qpow((type<0)?ipr:pr,(MOD-1)/i);
		for(int j=0;j<len;j+=i){
			for(int k=0,w=1;k<(i>>1);k++,w=1ll*w*W%MOD){
				int X=a[j+k],Y=1ll*a[(i>>1)+j+k]*w%MOD;
				a[j+k]=(X+Y)%MOD;a[(i>>1)+j+k]=(X-Y+MOD)%MOD;
			}
		}
	}
	if(!~type){
		int iv=qpow(len,MOD-2);
		for(int i=0;i<len;i++) a[i]=1ll*a[i]*iv%MOD;
	}
}
vector<int> conv(vector<int> a,vector<int> b){
	int LEN=1;while(LEN<a.size()+b.size()) LEN<<=1;
	a.resize(LEN,0);b.resize(LEN,0);NTT(a,LEN,1);NTT(b,LEN,1);
	for(int i=0;i<LEN;i++) a[i]=1ll*a[i]*b[i]%MOD;
	NTT(a,LEN,-1);return a;
}
vector<int> getinv(vector<int> a,int len){
	vector<int> b(len,0);b[0]=qpow(a[0],MOD-2);
	for(int i=2;i<=len;i<<=1){
		vector<int> c(b.begin(),b.begin()+(i>>1));
		vector<int> d(a.begin(),a.begin()+i);
		c=conv(c,c);d=conv(c,d);
		for(int j=0;j<i;j++) b[j]=(2*b[j]%MOD-d[j]+MOD)%MOD;
	} return b;
}
int inv[MAXP+5];
vector<int> direv(vector<int> a,int len){
	vector<int> b(len,0);
	for(int i=1;i<len;i++) b[i-1]=1ll*i*a[i]%MOD;
	return b;
}
vector<int> inter(vector<int> a,int len){
	vector<int> b(len,0);
	for(int i=1;i<len;i++) b[i]=1ll*inv[i]*a[i-1]%MOD;
	return b;
}
vector<int> getln(vector<int> a,int len){
	vector<int> b=getinv(a,len),b_=direv(a,len);
	b=conv(b,b_);b=inter(b,len);return b;
}
vector<int> getexp(vector<int> a,int len){
	vector<int> b(len,0);b[0]=1;
	for(int i=2;i<=len;i<<=1){
		vector<int> c(b.begin(),b.begin()+i);c=getln(c,i);
		vector<int> d(b.begin(),b.begin()+(i>>1));
		for(int j=0;j<i;j++) c[j]=(a[j]-c[j]+MOD)%MOD;(c[0]+=1)%=MOD;
		c=conv(c,d);for(int j=0;j<i;j++) b[j]=c[j];
	} return b;
}
/*template ends*/
int dp[MAXN+5];
void solve(int l,int r){
	if(l==r) return;int mid=l+r>>1;solve(l,mid);
	vector<int> A;for(int i=l;i<=mid;i++) A.pb(dp[i]);
	vector<int> B;for(int i=0;i<=r-l;i++) B.pb(cnt[i]);
	vector<int> C=conv(A,B);
	for(int i=mid+1;i<=r;i++) dp[i]=(dp[i]+C[i-l])%MOD;
	solve(mid+1,r);
}
int main(){
	for(int i=(inv[0]=inv[1]=1)+1;i<=MAXP;i++) inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		int len;scanf("%d",&len);
		vector<int> vec;
		for(int j=1,x;j<=len;j++){
			scanf("%d",&x);vec.pb(x);
			adde(x,i+k);adde(i+k,x);
		}
		for(int j=1;j<len;j++) in[vec[j]].insert(vec[j-1]),out[vec[j-1]].insert(vec[j]);
		for(int j=1;j<len;j++) merge(vec[0],vec[j],j);
		for(int j=0;j<len;j++) if(getsum(vec[j])!=getsum(vec[0])+j) ban[vec[j]]=1;
	}
	for(int i=1;i<=k;i++) if(in[i].size()>=2||out[i].size()>=2) ban[i]=1;
	for(int i=1;i<=k;i++) if(!vis[i]){
		flg=siz=0;dfs(i);
		if(!flg) cnt[siz]++/*,printf("%d\n",siz)*/;
	} /*puts("-1");*/
	dp[0]=1;solve(0,m);
	printf("%d\n",dp[m]);
	return 0;
}
/*
3 4 4
2 1 2
2 3 4
3 1 2 3

3 4 4
2 1 2
2 3 4
3 2 3 4
*/
/*
2 4 4
3 1 2 3
2 4 3

2 3 3
2 1 2
2 1 3
*/