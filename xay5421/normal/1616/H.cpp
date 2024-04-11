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
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=998244353;
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
int X;
vector<int>pw;
void debug(const vector<int>&a){
	D("{");
	rep(i,0,SZ(a)-1)D("%d%c",a[i],i==SZ(a)-1?'}':',');
}
int sol2(const vector<int>&a,const vector<int>&b,int bit){ //  (a^b)<=X||
	if(a.empty()||b.empty()){
		return su(pw[SZ(a)+SZ(b)],1);
	}
	if(bit<0){
		return su(pw[SZ(a)+SZ(b)],1);
	}
	vector<int>aa[2],bb[2];
	for(auto&x:a){
		aa[x>>bit&1].pb(x);
	}
	for(auto&x:b){
		bb[x>>bit&1].pb(x);
	}
	if(~X>>bit&1){
		int res=ad(sol2(aa[0],bb[0],bit-1),sol2(aa[1],bb[1],bit-1));
		uad(res,mu(su(pw[SZ(aa[0])],1),su(pw[SZ(aa[1])],1)));
		uad(res,mu(su(pw[SZ(bb[0])],1),su(pw[SZ(bb[1])],1)));
		return res;
	}else{
		int res1=sol2(aa[0],bb[1],bit-1);
		int res2=sol2(aa[1],bb[0],bit-1);
		return su(mu(res1+1,res2+1),1);
	}
}
int sol1(const vector<int>&a,int bit){
	if(a.empty())return 0;
	if(bit<0){
		return su(pw[SZ(a)],1);
	}
	vector<int>aa[2];
	for(auto&x:a){
		aa[x>>bit&1].pb(x);
	}
	if(~X>>bit&1){
		int res=ad(sol1(aa[0],bit-1),sol1(aa[1],bit-1));
		return res;
	}else{
		int res=sol2(aa[0],aa[1],bit-1);
		return res;
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	int n;
	scanf("%d%d",&n,&X);
	vector<int>a(n);
	pw.assign(n+1,0);
	pw[0]=1;
	rep(i,1,n)pw[i]=ad(pw[i-1],pw[i-1]);
	rep(i,0,n-1){
		scanf("%d",&a[i]);
	}
	printf("%d\n",sol1(a,30));
	return 0;
}