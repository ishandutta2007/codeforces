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
class dsu{
public:
	int n;
	vector<int>fa;
	vector<int>sz;
	dsu(){}
	dsu(int n_):n(n_),fa(n_),sz(n_,1){
		iota(fa.begin(),fa.end(),0);
	}
	void assign(int n_){
		*this=dsu(n_);
	}
	int find(int u){
		return fa[u]==u?u:fa[u]=find(fa[u]);
	}
	bool check(int u,int v){
		return find(u)==find(v);
	}
	bool unite(int u,int v){
		int u_=find(u);
		int v_=find(v);
		if(u_!=v_){
			if(sz[v_]<sz[u_]){
				int tmp=u_;
				u_=v_;
				v_=tmp;
			}
			sz[v_]+=sz[u_];
			fa[u_]=v_;
			return 1;
		}
		return 0;
	}
};
template<int P>
class mod_int{
	using Z=mod_int;
private:
	static int mo(int x){return x<0?x+P:x;}
public:
	int x;
	int val()const{return x;}
	mod_int():x(0){}
	template<class T>mod_int(const T&x_):x(x_>=0&&x_<P?static_cast<int>(x_):mo(static_cast<int>(x_%P))){}
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
const int P=1e9+7;
using Z=mod_int<P>;
const int N=65;
int n,a[N];
Z ans=1,C[N][N];
int tmp;
Z sol(vector<int>v){
	vector<int>deg(SZ(v));
	rep(i,0,SZ(v)-1)rep(j,0,SZ(v)-1)if(i!=j){
		if(v[j]%v[i]==0)++deg[j];
	}
	vector<int>S,T;
	rep(i,0,SZ(v)-1)if(!deg[i])S.pb(v[i]);else T.pb(v[i]);
	vector<vector<Z> >f(1<<SZ(S),vector<Z>(SZ(T)+1,0));
	vector<int>e(SZ(T));
	rep(i,0,SZ(T)-1){
		rep(j,0,SZ(S)-1){
			if(T[i]%S[j]==0){
				e[i]|=1<<j;
			}
		}
	}
	if(T.empty())return 1;
	rep(i,0,SZ(T)-1){
		f[e[i]][1]+=1;
	}
	DD(S,T);
	rep(mask,0,(1<<SZ(S))-1){
		rep(i,0,SZ(T)-1){
			Z u=f[mask][i];
			if(!u.val())continue;
			
			DD(mask,i,u);
			
			int tot=0;
			rep(j,0,SZ(T)-1)if((e[j]&mask)==e[j])++tot;else if(e[j]&mask)f[mask|e[j]][i+1]+=u;
			f[mask][i+1]+=u*(tot-i);
		}
	}
	DD(f[(1<<SZ(S))-1][SZ(T)]);
	Z ret=f[(1<<SZ(S))-1][SZ(T)]*C[tmp+SZ(T)-1][tmp];
	tmp+=SZ(T)-1;
	return ret;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rep(i,0,N-1){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	dsu o(n+1);
	rep(i,1,n)rep(j,1,n)if(i!=j&&a[i]%a[j]==0)o.unite(i,j);
	vector<vector<int> >v(n+1);
	rep(i,1,n)v[o.find(i)].pb(a[i]);
	rep(i,1,n)if(o.find(i)==i)ans*=sol(v[i]);
	printf("%d\n",ans.val());
	return 0;
}