#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;
const LL P = 998244353;
const int N = 2e6+5;

int n, m;
LL fac[N], ifac[N];
LL sec, iter;

LL pw(LL x, int n){
	LL res = 1;
	for(;n;n>>=1,x=x*x%P) if(n&1) res=res*x%P;
	return res;
}

inline LL inv(int x){return fac[x-1] * ifac[x] % P;}

int main(){
	cin>>n>>m;
	
	int maxn = max(n,m+1);
	fac[0] = 1;
	rep(i,1,maxn) fac[i] = fac[i-1] * i % P;
	ifac[maxn] = pw(fac[maxn], P-2);
	rrep(i,maxn-1,0) ifac[i] = ifac[i+1] * (i+1) % P;
	
	sec = (m+n+1) * inv(m+1) % P;
	rep(i,1,n) iter = (iter + inv(i)) % P;
	iter = (iter * m + 1) % P;
	cout<<sec * iter % P<<endl;
	
	return 0; 
}