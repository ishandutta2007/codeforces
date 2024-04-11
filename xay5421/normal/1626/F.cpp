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
const int X=720720;
int n,a0,x,y,K,mod;
Z cnt[X+5];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	cin>>n>>a0>>x>>y>>K>>mod;
	Z sum=0;
	auto ps=[&](int v){
		sum+=v;
		cnt[v%X]+=1;
	};
	ps(a0);
	rep(i,1,n-1){
		a0=(1LL*a0*x+y)%mod;
		ps(a0);
	}
	Z ans=0;
	const Z invn=Z(n).inv();
	rep(i,1,K){
		ans+=sum;
		for(int j=0;j<X;j+=i){
			rep(k,1,i-1){
				Z t=cnt[j+k]*invn;
				sum-=k*t;
				cnt[j]+=t,cnt[j+k]-=t;
			}
		}
	}
	ans=ans*Z(n).pow(K-1);
	printf("%d\n",ans.val());
	return 0;
}