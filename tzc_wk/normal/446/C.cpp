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
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
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
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=3e5;
const int MOD=1e9+9;
int n,qu,a[MAXN+5],fib[MAXN+5],fib_neg[MAXN+5],sum[MAXN+5];
struct node{int l,r,sum1,sum2,val1,val2,lz1,lz2;} s[MAXN*4+5];
void pushup(int k){
	s[k].val1=(s[k<<1].val1+s[k<<1|1].val1)%MOD;
	s[k].val2=(s[k<<1].val2+s[k<<1|1].val2)%MOD;
}
void pushdown(int k){
	if(s[k].lz1||s[k].lz2){
		s[k<<1].val1=(s[k<<1].val1+1ll*s[k<<1].sum1*s[k].lz1)%MOD;
		s[k<<1].val2=(s[k<<1].val2+1ll*s[k<<1].sum2*s[k].lz2)%MOD;
		s[k<<1].lz1=(s[k<<1].lz1+s[k].lz1)%MOD;
		s[k<<1].lz2=(s[k<<1].lz2+s[k].lz2)%MOD;
		s[k<<1|1].val1=(s[k<<1|1].val1+1ll*s[k<<1|1].sum1*s[k].lz1)%MOD;
		s[k<<1|1].val2=(s[k<<1|1].val2+1ll*s[k<<1|1].sum2*s[k].lz2)%MOD;
		s[k<<1|1].lz1=(s[k<<1|1].lz1+s[k].lz1)%MOD;
		s[k<<1|1].lz2=(s[k<<1|1].lz2+s[k].lz2)%MOD;
		s[k].lz1=s[k].lz2=0;
	}
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r){s[k].sum1=fib[l];s[k].sum2=fib[l+1];return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	s[k].sum1=(s[k<<1].sum1+s[k<<1|1].sum1)%MOD;
	s[k].sum2=(s[k<<1].sum2+s[k<<1|1].sum2)%MOD;
}
void modify(int k,int l,int r,int v1,int v2){
	if(l<=s[k].l&&s[k].r<=r){
		s[k].lz1=(s[k].lz1+v1)%MOD;s[k].lz2=(s[k].lz2+v2)%MOD;
		s[k].val1=(s[k].val1+1ll*s[k].sum1*v1%MOD)%MOD;
		s[k].val2=(s[k].val2+1ll*s[k].sum2*v2%MOD)%MOD;
		return;
	} pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,v1,v2);
	else if(l>mid) modify(k<<1|1,l,r,v1,v2);
	else modify(k<<1,l,mid,v1,v2),modify(k<<1|1,mid+1,r,v1,v2);
	pushup(k);
}
int query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return (s[k].val1+s[k].val2)%MOD;
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return (query(k<<1,l,mid)+query(k<<1|1,mid+1,r))%MOD;
}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=(sum[i-1]+a[i])%MOD;
	fib[1]=fib[2]=1;fib_neg[1]=1;fib_neg[2]=MOD-1;
	for(int i=3;i<=n+1;i++){
		fib[i]=(fib[i-1]+fib[i-2])%MOD;
		if(~i&1) fib_neg[i]=MOD-fib[i];
		else fib_neg[i]=fib[i];
	} build(1,1,n);
	while(qu--){
		int opt,l,r;scanf("%d%d%d",&opt,&l,&r);
		if(opt==1) modify(1,l,r,fib_neg[l],fib_neg[l-1]);
		else printf("%d\n",((sum[r]-sum[l-1]+MOD)%MOD+query(1,l,r))%MOD);
	}
	return 0;
}