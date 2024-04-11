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
const int MAXN=2e5;
const int MOD=1e9+7;
int qpow(int x,int e=MOD-2){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n=1,qu,v[MAXN+5];
struct event{int opt,a,b;} a[MAXN+5];
int hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0,fa[MAXN+5];
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int bgt[MAXN+5],edt[MAXN+5],tim=0,cnt[MAXN+5];
void dfs0(int x){
	bgt[x]=++tim;
	for(int e=hd[x];e;e=nxt[e]) dfs0(to[e]);
	edt[x]=tim;
}
struct node{int l,r,sum_mul,sum_mul_w,lz;} s[MAXN*4+5];
void pushup(int k){
	s[k].sum_mul=(s[k<<1].sum_mul+s[k<<1|1].sum_mul)%MOD;
	s[k].sum_mul_w=(s[k<<1].sum_mul_w+s[k<<1|1].sum_mul_w)%MOD;
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].lz=1;if(l==r){s[k].sum_mul=1;return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
}
void pushdown(int k){
	if(s[k].lz^1){
		s[k<<1].lz=1ll*s[k<<1].lz*s[k].lz%MOD;
		s[k<<1].sum_mul=1ll*s[k<<1].sum_mul*s[k].lz%MOD;
		s[k<<1].sum_mul_w=1ll*s[k<<1].sum_mul_w*s[k].lz%MOD;
		s[k<<1|1].lz=1ll*s[k<<1|1].lz*s[k].lz%MOD;
		s[k<<1|1].sum_mul=1ll*s[k<<1|1].sum_mul*s[k].lz%MOD;
		s[k<<1|1].sum_mul_w=1ll*s[k<<1|1].sum_mul_w*s[k].lz%MOD;
		s[k].lz=1;
	}
}
void mul(int k,int l,int r,int x){
	if(l<=s[k].l&&s[k].r<=r){
		s[k].lz=1ll*s[k].lz*x%MOD;
		s[k].sum_mul=1ll*s[k].sum_mul*x%MOD;
		s[k].sum_mul_w=1ll*s[k].sum_mul_w*x%MOD;
		return;
	} pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) mul(k<<1,l,r,x);
	else if(l>mid) mul(k<<1|1,l,r,x);
	else mul(k<<1,l,mid,x),mul(k<<1|1,mid+1,r,x);
	pushup(k);
}
void modify_w(int k,int x,int w){
	if(s[k].l==s[k].r){s[k].sum_mul_w=1ll*s[k].sum_mul*w%MOD;return;}
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(x<=mid) modify_w(k<<1,x,w);else modify_w(k<<1|1,x,w);
	pushup(k);
}
int query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].sum_mul_w;
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return (query(k<<1,l,mid)+query(k<<1|1,mid+1,r))%MOD;
}
int ask(int k,int x){
	if(s[k].l==s[k].r) return s[k].sum_mul;
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	return (x<=mid)?ask(k<<1,x):ask(k<<1|1,x);
}
int main(){
	scanf("%d%d",&v[1],&qu);
	for(int i=1;i<=qu;i++){
		scanf("%d",&a[i].opt);
		if(a[i].opt==1){
			scanf("%d%d",&a[i].a,&v[++n]);
			a[i].b=n;adde(a[i].a,a[i].b);
			fa[n]=a[i].a;
		} else scanf("%d",&a[i].a);
	} dfs0(1);build(1,1,n);modify_w(1,1,v[1]);
	for(int i=1;i<=n;i++) cnt[i]=1;
	for(int i=1;i<=qu;i++){
		if(a[i].opt==1){
			modify_w(1,bgt[a[i].b],v[a[i].b]);
			mul(1,bgt[a[i].a],edt[a[i].a],1ll*(cnt[a[i].a]+1)*qpow(cnt[a[i].a])%MOD);
			cnt[a[i].a]++;
		} else {
			int div=(a[i].a==1)?1:ask(1,bgt[fa[a[i].a]]);
			printf("%d\n",1ll*query(1,bgt[a[i].a],edt[a[i].a])*qpow(div)%MOD);
		}
	}
	return 0;
}