#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=998244353;
inline int mo2(int x){return x<0?x+P:x;}
template<class T>inline int mo(const T&x){return mo2(static_cast<int>(x%P));}
struct Z{
	int x;
	int val()const{return x;}
	Z():x(0){}
	template<class T>Z(T x_):x(x_>=0&&x_<P?static_cast<int>(x_):mo(x_)){}
	bool operator==(const Z&rhs)const{return x==rhs.x;}
	bool operator!=(const Z&rhs)const{return x!=rhs.x;}
	Z operator-()const{return Z(mo2(-x));}
	Z pow(long long k)const{
		Z res=1,t=*this;
		while(k){
			if(k&1)res*=t;
			if(k>>=1)t*=t;
		}
		return res;
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
		x=1ULL*x*rhs.x%P;
		return *this;
	}
	Z&operator/=(const Z&rhs){
		return *this*=rhs.inv();
	}
#define setO(T,o) friend T operator o(const Z&lhs,const Z&rhs){Z res=lhs;return res o##=rhs;}
	setO(Z,+)setO(Z,-)setO(Z,*)setO(Z,/)
#undef setO
};
const int N=1000005;
int T,n,a[N],b[N];
int p[N],phi[N];
bool ban[N];
Z fac[N],ifac[N];
void sieve(){
	ban[0]=ban[1]=1,phi[1]=1;
	rep(i,2,N-1){
		if(!ban[i]){
			p[++*p]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}else{
				phi[i*p[j]]=phi[i]*(p[j]-1);
			}
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	fac[0]=1;
	rep(i,1,N-1)fac[i]=fac[i-1]*i;
	ifac[N-1]=fac[N-1].inv();
	per(i,N-1,1)ifac[i-1]=ifac[i]*i;
	sieve();
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		fill(b+1,b+n+1,0);
		rep(i,1,n)scanf("%d",&a[i]),++b[a[i]];
		if(count(a+1,a+n+1,a[1])==n){
			puts("1");
			continue;
		}
		int g=0;
		rep(i,1,n)g=__gcd(g,b[i]);
		Z ans1=0,ans2=0;
		rep(i,1,g)if(g%i==0){
			int sz=i;
			int cnt=n/sz;
			Z all=fac[cnt];
			rep(j,1,n)all*=ifac[b[j]/sz];
			ans2+=all*phi[i];
			Z t=0;
			rep(j,1,n)if(b[j]/sz>1){
				t+=all*b[j]*(b[j]/sz-1)/(cnt-1);
			}
			t*=phi[i];
			ans1+=t;
		}
		Z ans=ans1/ans2;
		ans=n-ans;
		printf("%d\n",ans.val());
	}
	return 0;
}