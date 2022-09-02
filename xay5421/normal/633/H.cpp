#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
int P;
struct FastMod {
	unsigned long long b, m;
	FastMod(unsigned long long b) : b(b), m((unsigned long long)((__uint128_t(1) << 64) / b)) {}
	unsigned long long reduce(unsigned long long a) {
		unsigned long long q = (unsigned long long)((__uint128_t(m) * a) >> 64);
		unsigned long long r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
}M(998244353);
int ad(int k1,int k2){return k1+k2>=P?k1+k2-P:k1+k2;}
int su(int k1,int k2){return k1-k2<0?k1-k2+P:k1-k2;}
int mu(int k1,int k2){return M.reduce(1ULL*k1*k2%P);}
void uad(int&k1,int k2){(k1+=k2)>=P&&(k1-=P);}
void usu(int&k1,int k2){(k1-=k2)<0&&(k1+=P);}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=30005,B=250;
int n,Q,a[N],num[N],num0,ans[N];
struct node{
	int l,r,id;
	bool operator<(const node&rhs)const{
		if(l/B==rhs.l/B)return l/B&1?r<rhs.r:r>rhs.r;
		return l<rhs.l;
	}
}qs[N];

int cnt[N];

struct mat{
	int a[2][2];
	mat operator*(const mat&rhs)const{
		mat ret;
		rep(i,0,1)rep(j,0,1){
			ret.a[i][j]=M.reduce(1ULL*a[i][0]*rhs.a[0][j]+1ULL*a[i][1]*rhs.a[1][j]);
		}
		return ret;
	}
};
struct vec{
	int a[2];
	vec operator*(const mat&rhs)const{
		return (vec){{int(M.reduce(1ULL*a[0]*rhs.a[0][0]+1ULL*a[1]*rhs.a[1][0])),int(M.reduce(1ULL*a[0]*rhs.a[0][1]+1ULL*a[1]*rhs.a[1][1]))}};
	}
	vec operator+(const vec&rhs)const{
		return (vec){{ad(a[0],rhs.a[0]),ad(a[1],rhs.a[1])}};
	}
};

struct segtree{
	mat tg[N*4];
	vec sum[N*4];
	bool hv[N*4];
	void pst(int k1,const mat&k2){
		if(!hv[k1]){
			hv[k1]=1;
			tg[k1]=k2;
			sum[k1]=sum[k1]*k2;
		}else{
			tg[k1]=tg[k1]*k2;
			sum[k1]=sum[k1]*k2;
		}
	}
	void psd(int k1){
		if(hv[k1]){
			pst(k1*2,tg[k1]);
			pst(k1*2+1,tg[k1]);
			hv[k1]=0;
		}
	}
	void upd(int k1){
		sum[k1]=sum[k1*2]+sum[k1*2+1];
	}
	void mdf(int k1,int k2,int k3,int k4,int k5,const mat&k6){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){pst(k1,k6);return;}
		psd(k1);
		int mid=(k2+k3)>>1;
		mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
		upd(k1);
	}
	void change(int k1,int k2,int k3,int k4,const vec&k5){
		if(k2==k3){
			sum[k1]=k5;
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		if(k4<=mid)change(k1*2,k2,mid,k4,k5);else change(k1*2+1,mid+1,k3,k4,k5);
		upd(k1);
	}
}sgt;

struct fenwick{
	int t[N];
	void add(int x,int y){for(int i=x;i<=num0;i+=i&-i)t[i]+=y;}
	int qry(int x){int y=0;for(int i=x;i;i&=i-1)y+=t[i];return y;}	
}fwk;

int F[N];

int tt;
void push(int x){
	++tt;
	if(++cnt[x]==1){
		int tmp=fwk.qry(x);
		fwk.add(x,1);
		sgt.mdf(1,1,num0,x,num0,(mat){{{1,1},{1,0}}});
		sgt.change(1,1,num0,x,(vec){mu(num[x],F[tmp+1]),mu(num[x],F[tmp])});
	}
}

void pop(int x){
	++tt;
	if(!--cnt[x]){
		fwk.add(x,-1);
		sgt.mdf(1,1,num0,x,num0,(mat){{{0,1},{1,P-1}}});
		sgt.change(1,1,num0,x,(vec){0,0});
	}
}

int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(P);
	M=FastMod(P);
	F[1]=1;
	rep(i,2,N-1)F[i]=ad(F[i-1],F[i-2]);
	rep(i,1,n)rd(a[i]),num[i]=a[i];
	
	sort(num+1,num+n+1);
	num0=unique(num+1,num+n+1)-num-1;
	rep(i,1,n)a[i]=lower_bound(num+1,num+num0+1,a[i])-num;
	
	rd(Q);
	rep(i,1,Q)rd(qs[i].l),rd(qs[i].r),qs[i].id=i;
	sort(qs+1,qs+Q+1);
	int ql=1,qr=0;
	
	rep(i,1,Q){
		DD(i,tt);
		while(ql>qs[i].l){
			push(a[--ql]);
		}
		while(qr<qs[i].r){
			push(a[++qr]);
		}
		while(ql<qs[i].l){
			pop(a[ql++]);
		}
		while(qr>qs[i].r){
			pop(a[qr--]);
		}
		ans[qs[i].id]=sgt.sum[1].a[0];
	}
	rep(i,1,Q)printf("%d\n",ans[i]);
	return 0;
}