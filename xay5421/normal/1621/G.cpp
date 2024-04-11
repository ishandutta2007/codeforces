#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>
struct fenwick{
	int n;
	vector<T>t;
	fenwick(int n):n(n),t(n){}
	void add(int x,const T&y){ // 0<=x
		++x;
		for(int i=x;i<=n;i+=i&-i)t[i-1]+=y;
	}
	void add(int l,int r,const T&x){ // [l,r]
		add(l,x);
		add(r+1,-x);
	}
	T query(int x){ // x<n
		if(x<0)return 0;
		++x;
		T y=0;
		for(int i=x;i;i&=i-1)y+=t[i-1];
		return y;
	}
	T query(int l,int r){ // [l,r]
		return query(r)-query(l-1);
	}
};

const int P=1e9+7;
template<class T,class U>
T power(T a,U b){
	T c=1;
	while(b){
		if(b&1)c*=a;
		if(b>>=1)a*=a;
	}
	return c;
}
inline int mo1(int x){if(x>=P)x-=P;return x;}
inline int mo2(int x){if(x<0)x+=P;return x;}
template<class T>inline int mo(const T&x){return mo2(static_cast<int>(x%P));}
struct Z{
	int x;
	int val(){return x;}
	Z(int x_=0):x(x_){}
	template<class T>Z(T x_):x(x_){}
	Z operator-()const{return Z(mo1(P-x));}
	Z inv()const{
#ifdef xay5421
		assert(x!=0);
#endif
		return power(*this,P-2);
	}
	Z&operator*=(const Z&rhs){
		x=1ULL*x*rhs.x%P;
		return *this;
	}
	Z&operator+=(const Z&rhs){
		x=mo1(x+rhs.x);
		return *this;
	}
	Z&operator-=(const Z&rhs){
		x=mo2(x-rhs.x);
		return *this;
	}
	Z&operator/=(const Z&rhs){
		return *this*=rhs.inv();
	}
#define setO(T,o) T operator o(const T&rhs)const{T res=*this;return res o##=rhs;}
	setO(Z,+)setO(Z,-)setO(Z,*)setO(Z,/)
#undef setO
};

struct node{
	int x;
	Z v;
	node(int x_=0,Z v_=0):x(x_),v(v_){}
	node operator-()const{
		return (node){x,-v};
	}
	node&operator+=(const node&rhs){
		if(x<rhs.x){
			x=rhs.x,v=rhs.v;
		}else if(x==rhs.x){
			v+=rhs.v;
		}
		return *this;
	}
	node&operator-=(const node&rhs){
		return *this+=-rhs;
	}
#define setO(T,o) T operator o(const T&rhs)const{T res=*this;return res o##=rhs;}
	setO(node,+)setO(node,-)
#undef setO
};
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		vector<int>a(n),id(n);
		rep(i,0,n-1)scanf("%d",&a[i]);
		iota(id.begin(),id.end(),0);
		sort(id.begin(),id.end(),[&](int lhs,int rhs){
			if(a[lhs]!=a[rhs])return a[lhs]<a[rhs];
			return lhs>rhs;
		});
		rep(i,0,n-1)a[id[i]]=i;
		vector<Z>f(n),g(n);
		fenwick<Z>tr(n);
		rep(i,0,n-1){
			f[i]=tr.query(a[i]-1)+1;
			tr.add(a[i],f[i]);
		}
		tr=fenwick<Z>(n);
		per(i,n-1,0){
			g[i]=tr.query(n-1-a[i])+1;
			tr.add(n-1-a[i],g[i]);
		}
		Z ans=0;
		rep(i,0,n-1){
			ans+=f[i]*g[i];
		}
		fenwick<node>t(n);
		per(i,n-1,0){
			node cur=t.query(n-1-a[i]);
			if(cur.x!=0){
				ans-=cur.v*f[i];
				t.add(n-1-a[i],node(cur.x,cur.v));
			}else{
				t.add(n-1-a[i],node(i,1));
				ans-=f[i];
			}
		}
		printf("%d\n",ans.val());
	}
	return 0;
}