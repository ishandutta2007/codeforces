// author: xay5421
// created: Sat Oct  2 23:42:43 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=200005,INF=0X3F3F3F3F;
int n,K,a[N],sz[N],f[N],rt,full;
bool ban[N];
vector<pair<int,int> >e[N];
void getrt(int k1,int k2){
	sz[k1]=1,f[k1]=0;
	for(auto x:e[k1])if(x.X!=k2&&!ban[x.X])getrt(x.X,k1),sz[k1]+=sz[x.X],f[k1]=max(f[k1],sz[x.X]);
	f[k1]=max(f[k1],full-sz[k1]);
	if(f[k1]<f[rt])rt=k1;
}
struct node{
	int u,cnt,sum;
};
vector<node>v;
vector<node>vec[2];
void dfs(int k1,int k2,int k3,int k4,int k5){
	v.pb((node){k1,k3,k5});
	for(auto x:e[k1])if(!ban[x.X]&&x.X!=k2){
		dfs(x.X,k1,k3+(x.Y!=k4),x.Y,ad(k5,a[x.X]));
	}
}
int bin[N],tot[N];
int calc1(vector<node>&v,int w){
	int mx=0;
	for(auto x:v)mx=max(mx,x.cnt);
	rep(i,0,mx)bin[i]=0,tot[i]=0;
	for(auto x:v)uad(bin[x.cnt],x.sum),++tot[x.cnt];
	rep(i,1,mx)uad(bin[i],bin[i-1]),tot[i]+=tot[i-1];
	int res=0;
	for(auto x:v){
		if(K-x.cnt>=0){
			int pos=min(mx,K-x.cnt);
			uad(res,bin[pos]);
			uad(res,mu(tot[pos],ad(x.sum,w)));
		}
	}
	for(auto x:v)if(x.cnt*2<=K)usu(res,mu(x.sum,2),w);
	return mu(res,(P+1)>>1);
}
int calc2(vector<node>&v0,vector<node>&v1,int w){
	int mx=0;
	for(auto x:v0)mx=max(mx,x.cnt);
	rep(i,0,mx)bin[i]=0,tot[i]=0;
	for(auto x:v0)uad(bin[x.cnt],x.sum),++tot[x.cnt];
	rep(i,1,mx)uad(bin[i],bin[i-1]),tot[i]+=tot[i-1];
	int res=0;
	for(auto x:v1){
		if(K-x.cnt-1>=0){
			int pos=min(mx,K-x.cnt-1);
			uad(res,bin[pos]);
			uad(res,mu(tot[pos],ad(x.sum,w)));
		}
	}
	return res;
}
int ans;
void sol(int k1){
	ban[k1]=1;
	vec[0].clear(),vec[1].clear();
	ans+=a[k1];
	for(auto x:e[k1])if(!ban[x.X]){
		v.clear();
		dfs(x.X,k1,0,x.Y,a[x.X]);
		usu(ans,calc1(v,a[k1]));
		for(auto cur:v){
			vec[x.Y].pb(cur);
			if(cur.cnt<=K){
				uad(ans,cur.sum,a[k1]);
			}
		}
	}
	uad(ans,calc1(vec[0],a[k1]));
	uad(ans,calc1(vec[1],a[k1]));
	uad(ans,calc2(vec[0],vec[1],a[k1]));
	//D("after %d ans=%d\n",k1,ans);
	int old=full;
	for(auto x:e[k1])if(!ban[x.X]){
		full=sz[x.X]<sz[k1]?sz[x.X]:old-sz[k1];
		rt=0;
		getrt(x.X,k1);
		sol(rt);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(K);
	rep(i,1,n)rd(a[i]);
	rep(i,2,n){
		int k1,k2,k3;
		rd(k1),rd(k2),rd(k3);
		e[k1].eb(k2,k3),e[k2].eb(k1,k3);
	}
	f[0]=INF;
	full=n;
	rt=0;
	getrt(1,0);
	sol(rt);
	printf("%d\n",ans);
	return 0;
}