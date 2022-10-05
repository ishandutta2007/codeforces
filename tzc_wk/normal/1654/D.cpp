//Created time: 2022/3/20 19:30:51
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
#ifdef FASTIO
#define FILE_SIZE 1<<23
char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
inline void putc(char x){(*p3++=x);}
template<typename T> void read(T &x){
	x=0;char c=getc();T neg=0;
	while(!isdigit(c)) neg|=(c=='-'),c=getc();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c-'0'),c=getc();
	if(neg) x=-x;
}
template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=-x;recursive_print(x);}
template<typename T> void print(T x,char c){print(x);putc(c);}
void readstr(char *s){
	char c=getc();
	while(c<=32||c>=127) c=getc();
	while(c>32&&c<127) s[0]=c,s++,c=getc();
	(*s)=0;
}
void printstr(string s){for(int i=0;i<s.size();i++) putc(s[i]);}
void printstr(char *s){int len=strlen(s);for(int i=0;i<len;i++) putc(s[i]);}
void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
#endif
const int MAXN=2e5;
const int MOD=998244353;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int pr[MAXN+5],prcnt,vis[MAXN+5],mnp[MAXN+5];
void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]) mnp[i]=i,pr[++prcnt]=i;
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			mnp[pr[j]*i]=pr[j];vis[pr[j]*i]=1;
			if(i%pr[j]==0) break;
		}
	}
}
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],X[MAXN*2+5],Y[MAXN*2+5],ec=0,prd=1,sum;
void adde(int u,int v,int x,int y){to[++ec]=v;X[ec]=x;Y[ec]=y;nxt[ec]=hd[u];hd[u]=ec;}
int buc[MAXN+5];set<int> used;
void dfs(int x,int f,int coef){
//	printf("%d\n",coef);
	sum=(sum+coef)%MOD;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],nx=X[e],ny=Y[e];if(y==f) continue;
		int iv=1ll*qpow(nx,MOD-2)*ny%MOD;
		vector<pii> facx,facy;
		while(nx^1){
			int p=mnp[nx],c=0;
			while(nx%p==0) nx/=p,c++;
			facx.pb(mp(p,c));
		}
		while(ny^1){
			int p=mnp[ny],c=0;
			while(ny%p==0) ny/=p,c++;
			facy.pb(mp(p,c));
		}
		for(pii p:facx){
			int nd=max(p.se-buc[p.fi],0);
			buc[p.fi]+=nd;buc[p.fi]-=p.se;
			prd=1ll*prd*qpow(p.fi,nd)%MOD;
			used.insert(p.fi);
		}
		for(pii p:facy) buc[p.fi]+=p.se,used.insert(p.fi);
		dfs(y,x,1ll*coef*iv%MOD);
		for(pii p:facx) buc[p.fi]+=p.se;
		for(pii p:facy) buc[p.fi]-=p.se;
	}
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) hd[i]=0;ec=0;
	prd=1;sum=0;used.clear();
	for(int i=1,u,v,x,y;i<n;i++){
		scanf("%d%d%d%d",&u,&v,&x,&y);
		int d=__gcd(x,y);x/=d;y/=d;
		adde(u,v,x,y);adde(v,u,y,x);
	}
	dfs(1,0,1);
	printf("%d\n",1ll*sum*prd%MOD);
	for(int pos:used) buc[pos]=0;
}
int main(){
	sieve(MAXN);
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}