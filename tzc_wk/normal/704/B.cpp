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
const int MAXN=5000;
int n,s,e,nxt[MAXN+5];
int x[MAXN+5],a[MAXN+5],b[MAXN+5],c[MAXN+5],d[MAXN+5];
ll calc(int i,int j){
	if(i>j) return 0ll+x[i]-x[j]+c[i]+b[j];
	else return 0ll+x[j]-x[i]+d[i]+a[j];
}
int main(){
	scanf("%d%d%d",&n,&s,&e);nxt[s]=e;
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	for(int i=1;i<=n;i++) if(i!=s&&i!=e){
		ll mn=0x3f3f3f3f3f3f3f3fll;int pos=0;
		for(int j=s;j!=e;j=nxt[j]){
			ll val=calc(j,i)+calc(i,nxt[j])-calc(j,nxt[j]);
			if(val<mn) mn=val,pos=j;
		} nxt[i]=nxt[pos];nxt[pos]=i;
	} ll res=0;
	for(int i=s;i!=e;i=nxt[i]) res+=calc(i,nxt[i]);
	printf("%lld\n",res);
	return 0;
}