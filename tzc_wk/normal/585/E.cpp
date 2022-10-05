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
const int MAXN=5e5;
const int MAXM=1e7;
const int MOD=1e9+7;
int n,pw[MAXN+5],c[MAXM+5],f[MAXM+5],g[MAXM+5];
int pr[MAXM/10+5],pcnt=0,mu[MAXM+5];
bitset<MAXM+5> vis;
void sieve(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){pr[++pcnt]=i;mu[i]=-1;}
		for(int j=1;j<=pcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;
			if(i%pr[j]==0) break;
			else mu[i*pr[j]]=-mu[i];
		}
	}
}
int main(){
	scanf("%d",&n);pw[0]=1;sieve(MAXM);
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%MOD;
	for(int i=1,x;i<=n;i++) scanf("%d",&x),c[x]++;
	for(int i=1;i<=pcnt;i++) for(int j=MAXM/pr[i];j;j--) c[j]+=c[j*pr[i]];
	for(int i=1;i<=MAXM;i++) f[i]=pw[c[i]]-1,g[i]=c[i]*mu[i];
	for(int i=1;i<=pcnt;i++) for(int j=1;j*pr[i]<=MAXM;j++) g[j*pr[i]]+=g[j];
	for(int i=1;i<=pcnt;i++) for(int j=1;j*pr[i]<=MAXM;j++) f[j]=(f[j]-f[j*pr[i]]+MOD)%MOD;
	int ans=0;for(int i=2;i<=MAXM;i++) ans=(ans+1ll*g[i]*f[i])%MOD;
	printf("%d\n",ans);
	return 0;
}