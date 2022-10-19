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
const int MAXN=4e5;
const int MOD=998244353;
int n,m,a[MAXN+5],b[MAXN+5];
int fac[MAXN+5],ifac[MAXN+5];
void init_fac(int n){
	for(int i=(fac[0]=ifac[0]=ifac[1]=1)+1;i<=n;i++) ifac[i]=1ll*ifac[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*ifac[i]%MOD;
}
int binom(int x,int y){return 1ll*fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;}
struct node{int ch[2],val,key,lz;} s[MAXN+5];
int rt,ncnt;
void clear(){
	for(int i=1;i<=ncnt;i++) s[i].ch[0]=s[i].ch[1]=s[i].val=s[i].key=s[i].lz=0;
	rt=ncnt=0;
}
void tag(int k,int v){s[k].val+=v;s[k].lz+=v;}
void pushdown(int k){
	if(s[k].lz){
		if(s[k].ch[0]) tag(s[k].ch[0],s[k].lz);
		if(s[k].ch[1]) tag(s[k].ch[1],s[k].lz);
		s[k].lz=0;
	}
}
void split(int k,int val,int &a,int &b){
	if(!k) return a=b=0,void();pushdown(k);
	if(s[k].val<=val) a=k,split(s[k].ch[1],val,s[k].ch[1],b);
	else b=k,split(s[k].ch[0],val,a,s[k].ch[0]);
}
int merge(int a,int b){
	if(!a||!b) return a+b;pushdown(a);pushdown(b);
	if(s[a].key<s[b].key) return s[a].ch[1]=merge(s[a].ch[1],b),a;
	else return s[b].ch[0]=merge(a,s[b].ch[0]),b;
}
bool check_in(int x){
	int k1,k2,k3;split(rt,x-1,k1,k2);split(k2,x,k2,k3);
	bool res=(k2>0);rt=merge(merge(k1,k2),k3);return res;
}
void insert(int x){
	int k1,k2;split(rt,x,k1,k2);++ncnt;
	s[ncnt].ch[0]=s[ncnt].ch[1]=0;s[ncnt].lz=0;
	s[ncnt].val=x;s[ncnt].key=rand();
	rt=merge(merge(k1,ncnt),k2);
}
void addgeq(int x){
	int k1,k2;split(rt,x-1,k1,k2);
	if(k2) tag(k2,1);rt=merge(k1,k2);
}
void solve(){
	scanf("%d%d",&n,&m);clear();int sum=0;
	for(int i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=m;i++){
		bool ins=!check_in(b[i]);addgeq(b[i]);
//		printf("%d\n",ins);
		if(ins) insert(b[i]+1),sum++;
	} printf("%d\n",binom(n+n-1-sum,n-1-sum));
}
int main(){
	srand(time(0));
	int qu;scanf("%d",&qu);init_fac(MAXN);
	while(qu--) solve();
	return 0;
}
/*
2
10 4
5 2
6 3
7 4
8 7
10 4
5 2
6 3
7 4
8 7
*/