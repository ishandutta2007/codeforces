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
namespace fenwick_helper{

template<class T>
T plus(const T&x,const T&y){
	return x+y;
}
template<class T>
T multiplies(const T&x,const T&y){
	return x*y;
}
template<class T>
T bit_xor(const T&x,const T&y){
	return x^y;
}
template<class T>
T min(const T&x,const T&y){
	return x<y?x:y;
}
template<class T>
T max(const T&x,const T&y){
	return x<y?y:x;
}
template<class T>
T e(){
	return T();
}

}
template<class T,T (*op)(const T&,const T&)=fenwick_helper::plus<T>,T (*e)()=fenwick_helper::e<T> >
struct fenwick{
	int n;
	vector<T>t;
	fenwick():n(0),t(0){}
	fenwick(int n):n(n),t(n,e()){}
	void assign(int n_){n=n_,t.assign(n_,e());}
	void add(int x,const T&y){ // 0<=x
		++x;
		for(int i=x;i<=n;i+=i&-i)t[i-1]=op(t[i-1],y);
	}
	void add(int l,int r,const T&x){ // [l,r]
		add(l,x);
		add(r+1,-x);
	}
	T query(int x){ // x<n
		++x;
		T y=e();
		for(int i=x;i>0;i&=i-1)y=op(y,t[i-1]);
		return y;
	}
	T query(int l,int r){ // [l,r]
		return op(query(r),-query(l-1)); // operator-()
	}
	void add2(int x,const T&y){ // x<n
		++x;
		for(int i=x;i>0;i&=i-1)t[i-1]=op(t[i-1],y);
	}
	T query2(int x){ // 0<=x
		++x;
		T y=e();
		for(int i=x;i<=n;i+=i&-i)y=op(y,t[i-1]);
		return y;
	}
};
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
LL inf(){
	return INFLL;
}
const int N=300005;
int n,Q,a[N],b[N],lc[N],rc[N],st[N],top;
LL ans[N];
vector<int>all[N];
vector<pair<int,int> >qs[N];
void dfs(int u,int l,int r){
	if(lc[u]){
		dfs(lc[u],l,u-1);
	}
	if(rc[u]){
		dfs(rc[u],u+1,r);
	}
	if(l)all[l-1].pb(u);
	if(r<n)all[u].pb(r+1);
}
int main(){
	rd(n),rd(Q);
	rep(i,1,n){
		rd(a[i]),rd(b[i]);
		while(top&&b[i]<=b[st[top]])lc[i]=st[top--];
		rc[st[top]]=i;
		st[++top]=i;
	}
	dfs(rc[0],1,n);
	rep(tc,1,Q){
		int l,r;
		rd(l),rd(r);
		qs[l].eb(r,tc);
	}
	fenwick<LL,fenwick_helper::min<LL>,inf>tr(n+1);
	auto calc=[&](int i,int j)->LL{
		return 1LL*(a[j]-a[i])*(b[i]+b[j]);
	};
	per(i,n,1){
		each(x,all[i]){
			DD(x,calc(i,x));
			tr.add(x,calc(i,x));
		}
		each(x,qs[i]){
			int r,tc;
			tie(r,tc)=x;
			ans[tc]=tr.query(r);
		}
	}
	rep(tc,1,Q)printf("%lld\n",ans[tc]);
	return 0;
}