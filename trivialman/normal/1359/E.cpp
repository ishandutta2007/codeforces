#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 998244353;
const int INF = 1e9;
const int N = 5e5+5;
const double pi = acos(-1);
mt19937 rng(time(0));
  
int n, k, fac[N], ifac[N];

LL pw(LL x, int n){
	LL res = 1;
	for(;n;n>>=1,x=x*x%P) if(n&1) res=res*x%P;
	return res;
}

int C(int a, int b){
	return 1ll * fac[a] * ifac[b] % P * ifac[a-b] % P;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	fac[0] = 1;
	rep(i,1,N-1) fac[i] = 1ll * fac[i-1] * i % P;
	ifac[N-1] = pw(fac[N-1], P-2);
	rrep(i,N-2,0) ifac[i] = 1ll * ifac[i+1] * (i+1) % P;
	
	cin>>n>>k;
	int ans = 0;
	rep(i,1,n/k) ans = (ans + C(n/i-1, k-1)) % P;
	cout<<ans<<endl;
	return 0;
}