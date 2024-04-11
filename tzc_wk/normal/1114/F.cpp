#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
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
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXV=300;
const int MAXN=4e5;
const int MOD=1e9+7;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
bitset<MAXV+5> vis;
int pr[MAXV/3+5],prcnt=0,phi[MAXV+5];
void sieve(int n){
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]) pr[++prcnt]=i;
		for(int j=1;pr[j]*i<=n&&j<=prcnt;j++){
			vis[pr[j]*i]=1;
			if(i%pr[j]==0) break;
		}
	}
}
int n,qu,a[MAXN+5];
struct node{int l,r,mul,lz;ll msk,tag_msk;} s[MAXN*4+5];
void pushup(int k){
	s[k].mul=1ll*s[k<<1].mul*s[k<<1|1].mul%MOD;
	s[k].msk=s[k<<1].msk|s[k<<1|1].msk;
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].lz=1;
	if(l==r){
		s[k].mul=a[l];
		for(int i=1;i<=prcnt;i++) if(a[l]%pr[i]==0)
			s[k].msk|=1ll<<(i-1);
		return;
	} int mid=(l+r)>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
void pushdown(int k){
	if(s[k].lz!=1){
		s[k<<1].mul=1ll*s[k<<1].mul*qpow(s[k].lz,s[k<<1].r-s[k<<1].l+1)%MOD;
		s[k<<1].lz=1ll*s[k<<1].lz*s[k].lz%MOD;
		s[k<<1].msk=s[k<<1].msk|s[k].tag_msk;
		s[k<<1].tag_msk=s[k<<1].tag_msk|s[k].tag_msk;
		s[k<<1|1].mul=1ll*s[k<<1|1].mul*qpow(s[k].lz,s[k<<1|1].r-s[k<<1|1].l+1)%MOD;
		s[k<<1|1].lz=1ll*s[k<<1|1].lz*s[k].lz%MOD;
		s[k<<1|1].msk=s[k<<1|1].msk|s[k].tag_msk;
		s[k<<1|1].tag_msk=s[k<<1|1].tag_msk|s[k].tag_msk;
		s[k].lz=1;s[k].tag_msk=0;
	}
}
void modify(int k,int l,int r,int x,ll y){
	if(l<=s[k].l&&s[k].r<=r){
		s[k].mul=1ll*s[k].mul*qpow(x,s[k].r-s[k].l+1)%MOD;s[k].msk|=y;
		s[k].lz=1ll*s[k].lz*x%MOD;s[k].tag_msk|=y;return;
	} pushdown(k);int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) modify(k<<1,l,r,x,y);
	else if(l>mid) modify(k<<1|1,l,r,x,y);
	else modify(k<<1,l,mid,x,y),modify(k<<1|1,mid+1,r,x,y);
	pushup(k);
}
int query_mul(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].mul;
	pushdown(k);int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) return query_mul(k<<1,l,r);
	else if(l>mid) return query_mul(k<<1|1,l,r);
	else return 1ll*query_mul(k<<1,l,mid)*query_mul(k<<1|1,mid+1,r)%MOD;
}
ll query_msk(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].msk;
	pushdown(k);int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) return query_msk(k<<1,l,r);
	else if(l>mid) return query_msk(k<<1|1,l,r);
	else return query_msk(k<<1,l,mid)|query_msk(k<<1|1,mid+1,r);
}
int main(){
	scanf("%d%d",&n,&qu);sieve(MAXV);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	while(qu--){
		static char opt[10];scanf("%s",opt+1);
		if(opt[1]=='M'){
			int l,r,x;scanf("%d%d%d",&l,&r,&x);
			ll msk=0;for(int i=1;i<=prcnt;i++) if(x%pr[i]==0) msk|=1ll<<(i-1);
			modify(1,l,r,x,msk);
		} else {
			int l,r;scanf("%d%d",&l,&r);
			int mul1=1,mul2=1,mul=query_mul(1,l,r);
			ll msk=query_msk(1,l,r);
			for(int i=1;i<=prcnt;i++) if(msk>>(i-1)&1){
				mul1=1ll*mul1*(pr[i]-1)%MOD;mul2=1ll*mul2*pr[i]%MOD;
			} mul=1ll*mul*mul1%MOD*qpow(mul2,MOD-2)%MOD;
			printf("%d\n",mul);
		}
	}
	return 0;
}
/*
5 2
2 3 5 7 11
MULTIPLY 1 5 13
TOTIENT 1 5
*/