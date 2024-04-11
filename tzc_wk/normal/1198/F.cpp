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
int n,m,a[MAXN+5],b[MAXN+5],p[MAXN+5];
int res[MAXN+5],pos[MAXN+5],tt[MAXN+5];
map<int,int> cnt,pre;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(++cnt[a[i]]<=2) b[++m]=a[i],p[m]=m,pos[m]=i,pre[a[i]]=i;
		else tt[i]=pre[a[i]];
	}
	while(clock()<0.45*CLOCKS_PER_SEC){
		random_shuffle(p+1,p+m+1);
		int d=0,ps=-1;
		for(int i=1;i<=m;i++){
			d=__gcd(d,b[p[i]]);
			if(d==1){ps=i;break;}
		} if(~ps){
			d=0;
			for(int i=ps+1;i<=m;i++) d=__gcd(d,b[p[i]]);
			if(d==1){
				puts("YES");
				for(int i=1;i<=ps;i++) res[pos[p[i]]]=1;
				for(int i=ps+1;i<=m;i++) res[pos[p[i]]]=2;
				for(int i=1;i<=n;i++) if(tt[i]) res[i]=res[tt[i]];
				for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
				return 0;
			}
		}
	} puts("NO");
	return 0;
}
/*
7
6 6 6 2 2 3 3
*/