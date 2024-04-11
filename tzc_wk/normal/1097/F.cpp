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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int MAXV=7000;
int mu[MAXV+5],pr[MAXV/4+5],prcnt=0,vis[MAXV+5];
bitset<MAXV+5> f[MAXN+5],g[MAXV+5],h[MAXV+5];
void sieve(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]) pr[++prcnt]=i,mu[i]=-1;
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;if(i%pr[j]==0) break;
			mu[i*pr[j]]=-mu[i];
		}
	}
	for(int i=1;i<=MAXV;i++) for(int j=i;j<=MAXV;j+=i)
		g[j].set(i),((!!mu[j/i])&&(h[i].set(j),0));
}
int main(){
	sieve(MAXV);int n,qu;scanf("%d%d",&n,&qu);
	while(qu--){
		int opt;scanf("%d",&opt);
		switch(opt){
			case 1:{int x,v;scanf("%d%d",&x,&v);f[x]=g[v];break;}
			case 2:{int x,y,z;scanf("%d%d%d",&x,&y,&z);f[x]=f[y]^f[z];break;}
			case 3:{int x,y,z;scanf("%d%d%d",&x,&y,&z);f[x]=f[y]&f[z];break;}
			case 4:{int x,v;scanf("%d%d",&x,&v);printf("%d",(f[x]&h[v]).count()&1);break;}
		}
	}
	return 0;
}