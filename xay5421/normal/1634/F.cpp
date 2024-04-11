#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.h"
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
inline char getc(){static char buf[1<<20],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getc()))f^=!(c^45);x=(c&15);while(isdigit(c=getc()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
struct FastMod {
	unsigned long long b, m;
	FastMod(unsigned long long b) : b(b), m((unsigned long long)((__uint128_t(1) << 64) / b)) {}
	unsigned long long reduce(unsigned long long a) {
		unsigned long long q = (unsigned long long)((__uint128_t(m) * a) >> 64);
		unsigned long long r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};
template<int id>
class dynamic_mod_int{
	using Z=dynamic_mod_int;
private:
	static int P;
	static FastMod M;
	static int mo(int x){return x<0?x+P:x;}
public:
	static void setP(int mod){P=mod,M=FastMod(mod);}
	int x;
	int val()const{return x;}
	dynamic_mod_int():x(0){}
	template<class T>dynamic_mod_int(const T&x_):x(x_>=0&&x_<P?static_cast<int>(x_):mo(static_cast<int>(x_%P))){}
	bool operator==(const Z&rhs)const{return x==rhs.x;}
	bool operator!=(const Z&rhs)const{return x!=rhs.x;}
	Z operator-()const{return Z(x?P-x:0);}
	Z pow(long long k)const{
		Z res=1,t=*this;
		while(k){
			if(k&1)res*=t;
			if(k>>=1)t*=t;
		}
		return res;
	}
	Z&operator++(){
		x<P-1?++x:x=0;
		return *this;
	}
	Z&operator--(){
		x?--x:x=P-1;
		return *this;
	}
	Z operator++(int){
		Z ret=x;
		x<P-1?++x:x=0;
		return ret;
	}
	Z operator--(int){
		Z ret=x;
		x?--x:x=P-1;
		return ret;
	}
	Z inv()const{
#ifdef xay5421
		assert(x!=0);
#endif
		return pow(P-2);
	}
	Z&operator+=(const Z&rhs){
		(x+=rhs.x)>=P&&(x-=P);
		return *this;
	}
	Z&operator-=(const Z&rhs){
		(x-=rhs.x)<0&&(x+=P);
		return *this;
	}
	Z&operator*=(const Z&rhs){
		x=M.reduce(1ULL*x*rhs.x);
		return *this;
	}
	Z&operator/=(const Z&rhs){
		return *this*=rhs.inv();
	}
#define setO(T,o) friend T operator o(const Z&lhs,const Z&rhs){Z res=lhs;return res o##=rhs;}
	setO(Z,+)setO(Z,-)setO(Z,*)setO(Z,/)
#undef setO
};
template<int id>FastMod dynamic_mod_int<id>::M(998244353);
template<int id>int dynamic_mod_int<id>::P(998244353);
using Z=dynamic_mod_int<0>;
const int N=300005;
int n,Q,P;
Z A[N];
struct mat{
	Z a[2][2];
	mat operator*(const mat&rhs)const{
		mat res;
		rep(i,0,1)rep(j,0,1){
			res.a[i][j]=a[i][0]*rhs.a[0][j]+a[i][1]*rhs.a[1][j];
		}
		return res;
	}
}pw[N];
struct node{
	Z x[2];
	int len;
	node trans(int l)const{
		return (node){{x[0]*pw[l].a[0][0]+x[1]*pw[l].a[1][0],x[0]*pw[l].a[0][1]+x[1]*pw[l].a[1][1]},len};
	}
	node operator+(const node&rhs)const{
		if(len==-1)return rhs;
		if(rhs.len==-1)return *this;
		if(len==1){
			if(rhs.len==1){
				return (node){{x[0],rhs.x[0]},len+rhs.len};
			}else{
				if(x[0]+rhs.x[0]==rhs.x[1]){
					return (node){{x[0],rhs.x[0]},len+rhs.len};
				}else{
					return (node){{-1,-1},-1};
				}
			}
		}else{
			node tmp=trans(len);
			if(rhs.len==1){
				if(tmp.x[0]==rhs.x[0]){
					return (node){{x[0],x[1]},len+rhs.len};
				}else{
					return (node){{-1,-1},-1};
				}
			}else{
				if(tmp.x[0]==rhs.x[0]&&tmp.x[1]==rhs.x[1]){
					return (node){{x[0],x[1]},len+rhs.len};
				}else{
					return (node){{-1,-1},-1};
				}
			}
		}
	}
}tr[N*4],tg[N*4];
int len[N*4];
void upd(int k1){
	tr[k1]=tr[k1*2]+tr[k1*2+1];
}
void bud(int k1,int k2,int k3){
	len[k1]=k3-k2+1;
	if(k2==k3){
		tr[k1]=(node){{A[k2],0},1};
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void pst(int k1,const node&k2){
	if(tr[k1].len!=-1){
		tr[k1].x[0]+=k2.x[0];
		if(tr[k1].len>=2)tr[k1].x[1]+=k2.x[1];
	}
	tg[k1].x[0]+=k2.x[0],tg[k1].x[1]+=k2.x[1];
}
void psd(int k1){
	if(tg[k1].x[0].val()||tg[k1].x[1].val()){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1].trans(len[k1*2]));
		tg[k1]=(node){{0,0},-1};
	}
}
void add(int k1,int k2,int k3,int k4,int k5,const node&k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		pst(k1,k6.trans(k2-k4));
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	add(k1*2,k2,mid,k4,k5,k6);
	add(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
void down(int k1,int k2,int k3){
	if(k2==k3){
		DD(k2,tr[k1].x[0]);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	down(k1*2,k2,mid),down(k1*2+1,mid+1,k3);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(Q),rd(P);
	if(P==1){
		while(Q--)puts("YES");
		return 0;
	}
	Z::setP(P);
	pw[0]=(mat){{{1,0},{0,1}}};
	pw[1]=(mat){{{0,1},{1,1}}};
	rep(i,1,N-1){
		pw[i]=pw[i-1]*pw[1];
	}
	rep(i,1,n){
		rd(A[i].x);
	}
	rep(i,1,n){
		int x;
		rd(x);
		A[i]-=x;
	}
	bud(1,1,n);
	rep(tc,1,Q){
		char ch;
		int l,r;
		while(ch=getc(),ch!='A'&&ch!='B');
		rd(l),rd(r);
		if(ch=='A'){
			add(1,1,n,l,r,(node){{1,1},-1});
		}else{
			add(1,1,n,l,r,(node){{-1,-1},-1});
		}
		//down(1,1,n);
		if(n==1){
			puts(tr[1].len==n&&tr[1].x[0]==0?"YES":"NO");
		}else{
			puts(tr[1].len==n&&tr[1].x[0]==0&&tr[1].x[1]==0?"YES":"NO");
		}
	}
	return 0;
}