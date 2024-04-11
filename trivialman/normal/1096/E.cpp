#include<bits/stdc++.h>
using namespace std;
#define N 5200
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

LL p,s,r,fac[N],ifac[N];

inline LL pw(LL x, LL n){
	LL y=1; n = (n + MOD-1) % (MOD-1);
	for(;n;n>>=1,x=x*x%MOD)y=(n&1)?y*x%MOD:y;
	return y;
}

inline LL C(LL n, LL m){
	return fac[n] * ifac[m] % MOD * ifac[n-m] % MOD;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	fac[0] = ifac[0] = 1;
	rep(i,1,N-1) fac[i] = fac[i-1] * i % MOD;
	ifac[N-1] = pw(fac[N-1],-1);
	for(int i=N-2;i;--i) ifac[i] = ifac[i+1] * (i+1) % MOD;
	cin>>p>>s>>r;
	LL tot = C(s-r+p-1,p-1), win = 0;
	rep(a1,max(r,(s+p-1)/p),s){
		if(a1==0) {win = pw(p,-1); break;}
		rep(tie,1,p){
			if(tie*a1>s)break;
			LL totsc = s - tie * a1, pop = p - tie, cnt = 0;
			rep(j,0,pop){
				LL tmpsc = totsc - a1 * j;
				if(tmpsc<0)break;
				cnt = (cnt + C(pop,j) * (pop==0&&tmpsc==0?1:C(tmpsc+pop-1,pop-1)) % MOD * (j&1?-1:1) + MOD) % MOD;
			}
			win = (win + cnt * C(p-1,tie-1) % MOD * pw(tie,-1)) % MOD;
		}
	}
	cout<<win*pw(tot,-1)%MOD<<endl;
	return 0;
}