#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
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
const int N=3005,M=3005;
int n,d,fa[N],v[N][M];
vector<int>e[N];
int lag(int y[M],int x){
	int res=0;
	rep(i,1,M-1){
		int fz=1,fm=1;
		rep(j,1,M-1)if(i!=j){
			fz=mu(fz,su(x,j));
			fm=mu(fm,su(i,j));
		}
		uad(res,mu(fz,po(fm,P-2),y[i]));
	}
	return res;
}
void F1(int y[M]){
	rep(i,1,M-1)uad(y[i],y[i-1]);
}
void F2(int y[M],int yy[M]){
	rep(i,1,M-1)y[i]=mu(y[i],yy[i]);
}
void dfs1(int k1){
	rep(i,1,M-1){
		v[k1][i]=1;
	}
	for(auto&x:e[k1]){
		dfs1(x);
		F1(v[x]);
		F2(v[k1],v[x]);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&d);
	rep(i,2,n)scanf("%d",&fa[i]),e[fa[i]].pb(i);
	dfs1(1);
	F1(v[1]);
	printf("%d\n",lag(v[1],d));
	return 0;
}