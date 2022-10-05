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
const int MAXN=3e5;
int n,m,p[MAXN+5],d[MAXN+5],ans[MAXN+5];ll t;
int get(ll x){return ((x%m+m)%m+m-1)%m+1;}
int getid(int x){return ((x%n+n)%n+n-1)%n+1;}
int id1[MAXN+5],id2[MAXN+5];
bool cmp1(int x,int y){return (p[x]^p[y])?(p[x]<p[y]):(!~d[x]);}
bool cmp2(int x,int y){return (get(p[x]+d[x]*t)^get(p[y]+d[y]*t))?
							  (get(p[x]+d[x]*t)<get(p[y]+d[y]*t)):(!~d[x]);}
int main(){
	scanf("%d%d%lld",&n,&m,&t);
	for(int i=1;i<=n;i++){
		char c;scanf("%d %c",&p[i],&c);
		d[i]=1-((c=='L')<<1);id1[i]=id2[i]=i;
	} sort(id1+1,id1+n+1,cmp1);sort(id2+1,id2+n+1,cmp2);
	int pos=0;
	if(!~d[1]){
		for(int i=1;i<=n;i++) if(~d[i]){
			ll x=p[1]-t,y=p[i]+t;
			if(p[1]<p[i]) y-=m;
			if(y>=x) pos=(pos+(y-x)/m+1)%n;
		} pos=getid(-pos);
	} else {
		for(int i=1;i<=n;i++) if(!~d[i]){
			ll x=p[1]+t,y=p[i]-t;
			if(p[1]>p[i]) y+=m;
			if(y<=x) pos=(pos+(x-y)/m+1)%n;
		}
	} int p1=0,p2=0;
	for(int i=1;i<=n;i++) if(id1[i]==1) p1=i;p1=getid(p1+pos);
	for(int i=1;i<=n;i++) if(id2[i]==1) p2=i;
//	for(int i=1;i<=n;i++) printf("%d%c",id1[i]," \n"[i==n]);
//	for(int i=1;i<=n;i++) printf("%d%c",id2[i]," \n"[i==n]);
//	printf("%d %d\n",p1,p2); 
	for(int i=0;i<n;i++){
		int tt=id2[getid(p2+i)];
		ans[id1[getid(p1+i)]]=get(p[tt]+d[tt]*t);
	} for(int i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}