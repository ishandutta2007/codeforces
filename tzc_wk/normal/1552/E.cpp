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
const int MAXN=100;
int n,k,c[MAXN*MAXN+5],p[MAXN+5],nxt[MAXN*MAXN+5];
pii res[MAXN+5];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n*k;i++) scanf("%d",&c[i]);
	for(int L=1;L<=n;L+=k-1){
		int R=min(L+k-2,n);vector<int> pos;
		for(int i=1;i<=n*k;i++) if(L<=c[i]&&c[i]<=R) pos.pb(i);
		memset(p,0,sizeof(p));memset(nxt,0,sizeof(nxt));
		for(int i=0;i<pos.size();i++){
			if(p[c[pos[i]]]) nxt[p[c[pos[i]]]]=pos[i];
			p[c[pos[i]]]=pos[i];
		}
		for(int i=L;i<=R;i++) nxt[p[i]]=n*k+1;nxt[n*k+1]=n*k+1;
		memset(p,0,sizeof(p));
		for(int i=0;i<pos.size();i++){
			if(p[c[pos[i]]]&&p[c[pos[i]]]!=pos[i]){
//				printf("%d %d\n",pos[i],p[c[pos[i]]]);
				res[c[pos[i]]]=mp(p[c[pos[i]]],pos[i]);
				p[c[pos[i]]]=0;
				for(int j=L;j<=R;j++) if(p[j]){
					while(p[j]<=pos[i]) p[j]=nxt[p[j]];
				}
			} else {
				if(!res[c[pos[i]]].fi) p[c[pos[i]]]=pos[i];
			}
		}
	} for(int i=1;i<=n;i++) printf("%d %d\n",res[i].fi,res[i].se);
	return 0;
}
/*
3 4
1 2 3 3 1 1 2 3 2 1 3 2
*/