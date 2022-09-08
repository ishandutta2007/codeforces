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
const int N=200005;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int n,t,g[N],c[N],d[N],L[N],R[N];
LL sum_d[N],dp[N];
int mod(LL x){
	x%=t;
	if(x<0)x+=t;
	return int(x);
}
struct node{
	int l,r;
	mutable int id;
	bool operator<(const node&rhs)const{
		return r<rhs.r;
	}
};
set<node>S;
set<node>::iterator split(int x){
	auto it=S.lower_bound((node){0,x,0});
	if(it==S.end()||it->l==x){
		return it;
	}
	auto cur=*it;
	S.erase(it);
	S.insert((node){cur.l,x-1,cur.id});
	return S.insert((node){x,cur.r,cur.id}).first;
}
void cover(int l,int r,int x){ // []
	if(l<=r){
		auto ed=split(r+1);
		auto bg=split(l);
		for(auto it=bg;it!=ed;){
			S.erase(it++);
		}
		S.insert((node){l,r,x});
	}else{
		cover(l,t-1,x);
		cover(0,r,x);
	}
}
int main(){
	rd(n),rd(t);
	rep(i,1,n)rd(g[i]),rd(c[i]);
	rep(i,1,n-1){
		rd(d[i]);
		sum_d[i]=sum_d[i-1]+d[i];
	}
	rep(i,1,n){
		c[i]=mod(c[i]+sum_d[i-1]);
		L[i]=mod(-c[i]);
		R[i]=mod(-c[i]+g[i]);
		// [L[i],R[i]) 
		// [R[i],L[i]) 
	}
	S.insert((node){0,t-1,n+1});
	dp[n+1]=0;
	per(i,n,1){
		auto it=S.lower_bound((node){0,L[i],0});
		assert(it!=S.end());
		dp[i]=dp[it->id]+(it->id==n+1?0:mod(L[it->id]-L[i]));
		// D("cover %d %d %d\n",R[i],mod(L[i]-1),i);
		cover(R[i],mod(L[i]-1),i);
	}
	LL ans=INFLL;
	each(u,S){
		if(u.id==n+1){
			ans=0;
		}else{
			ans=min(ans,dp[u.id]+mod(L[u.id]-u.r));
		}
	}
	ans+=sum_d[n-1];
	printf("%lld\n",ans);
	return 0;
}