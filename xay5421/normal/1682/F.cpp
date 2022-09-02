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
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
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
const int N=200005,M=N*40;
int n,Q,a[N],b[N];
LL sb[N];
int idx,rt[M],lc[M],rc[M],s1[M],s2[M];
vector<LL>num;
void ins(int&u,int v,int l,int r,int x,int y){
	u=++idx,lc[u]=lc[v],rc[u]=rc[v],s1[u]=s1[v],s2[u]=s2[v];
	if(l==r){
		uad(s1[u],y),uad(s2[u],mu((num[l]%P+P)%P,y));
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)ins(lc[u],lc[v],l,mid,x,y);
	else ins(rc[u],rc[v],mid+1,r,x,y);
	s1[u]=ad(s1[lc[u]],s1[rc[u]]);
	s2[u]=ad(s2[lc[u]],s2[rc[u]]);
}
int S1,S2;
void qry(int u,int v,int l,int r,int ll,int rr){
	if(l>rr||r<ll)return;
	if(ll<=l&&r<=rr){
		uad(S1,su(s1[u],s1[v]));
		uad(S2,su(s2[u],s2[v]));
		return;
	}
	int mid=(l+r)>>1;
	qry(lc[u],lc[v],l,mid,ll,rr),qry(rc[u],rc[v],mid+1,r,ll,rr);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(Q);
	rep(i,1,n)rd(a[i]);
	rep(i,1,n)rd(b[i]),sb[i]=sb[i-1]+b[i];
	rep(i,0,n)num.pb(sb[i]);
	sort(num.begin(),num.end()),num.erase(unique(num.begin(),num.end()),num.end());
	rep(i,0,n)sb[i]=lower_bound(num.begin(),num.end(),sb[i])-num.begin();
	rep(i,1,n-1){
		ins(rt[i],rt[i-1],0,SZ(num)-1,sb[i],a[i+1]-a[i]);
	}
	while(Q--){
		int l,r;
		rd(l),rd(r);
		int ans=0;
		/*rep(i,l,r-1){
			if(sb[i]-sb[l-1]>0){
				ans+=(sb[i]-sb[l-1])*(a[i+1]-a[i]);
			}else{
				ans+=(sb[l-1]-sb[i])*(a[i+1]-a[i]);
			}
		}*/
		S1=0,S2=0;
		qry(rt[r-1],rt[l-1],0,SZ(num)-1,0,sb[l-1]);
		uad(ans,mu(S1,int(num[sb[l-1]]%P+P)%P));
		usu(ans,S2);
		if(sb[l-1]<SZ(num)-1){
			S1=0,S2=0;
			qry(rt[r-1],rt[l-1],0,SZ(num)-1,sb[l-1]+1,SZ(num)-1);
			usu(ans,mu(S1,int(num[sb[l-1]]%P+P)%P));
			uad(ans,S2);
		}
		printf("%d\n",ans);
	}
	return 0;
}