//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int MAXNK=3e7;
int n,k,kx[MAXN+5],ky[MAXN+5];
int ux[MAXN+5],uy[MAXN+5],nx=0,ny=0;
pii p[MAXN+5];int sum[MAXNK+5];ll ans[MAXN+5];
int ys[MAXNK+5],cx,cy;
void insert(int x,int t,int v){
//	printf("%d %d %d\n",x,t,v);
	int ps=lower_bound(ys+1,ys+cy+1,p[x].se)-ys;
	assert(ps>=k-1);
	for(int i=ps-k+1;i<=ps;i++){
		ans[sum[i]]+=t;
		sum[i]+=v;
		ans[sum[i]]-=t;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].fi,&p[i].se);
		kx[i]=p[i].fi;ky[i]=p[i].se;
	} sort(kx+1,kx+n+1);sort(ky+1,ky+n+1);
	sort(p+1,p+n+1);kx[0]=ux[0]=ky[0]=uy[0]=-0x3f3f3f3f;
	for(int i=1;i<=n;i++) if(kx[i]^kx[i-1]) ux[++nx]=kx[i];
	for(int i=1;i<=n;i++) if(ky[i]^ky[i-1]) uy[++ny]=ky[i];
	for(int i=1;i<=ny;i++) for(int j=max(uy[i]-k+1,uy[i-1]+1);j<=uy[i];j++) ys[++cy]=j;
	int l=1,r=1;
	for(int i=1;i<=nx;i++) for(int j=max(ux[i]-k+1,ux[i-1]+1);j<=ux[i];j++){
		cx++;
		while(r<=n&&p[r].fi<j+k) insert(r++,cx,1);
		while(l<=n&&p[l].fi<j) insert(l++,cx,-1);
	} while(l<=n) insert(l++,cx+1,-1);
	for(int i=1;i<=n;i++) printf("%lld%c",ans[i]," \n"[i==n]);
	return 0;
}