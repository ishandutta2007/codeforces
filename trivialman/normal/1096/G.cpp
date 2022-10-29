#include<bits/stdc++.h>
using namespace std;
#define N 1048580
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

LL n,m,k,x,ans=0,id[N],a[N],b[N];

inline LL pw(LL x, LL n){
	LL y=1;
	for(;n;n>>=1,x=x*x%MOD)y=(n&1)?y*x%MOD:y;
	return y;
}

inline void NTT(LL *x, int t){
	rep(i,1,n-1)if(i<id[i])swap(x[i],x[id[i]]);
	for(int h=2;h<=n;h<<=1){
		LL wn = pw(3,t==1?(MOD-1)/h:MOD-1-(MOD-1)/h);
		for(int j=0;j<n;j+=h){
			LL w=1, tmp;
			rep(k,j,j+(h>>1)-1){
				tmp = x[k+(h>>1)] * w % MOD;
				x[k+(h>>1)] = (x[k] - tmp + MOD) % MOD;
				x[k] = (x[k] + tmp) % MOD;
				w = w * wn % MOD;
			}
		}
	}	
	if(t==-1){
		LL invn = pw(n,MOD-2);
		rep(i,0,n-1) x[i] = x[i] *invn % MOD;
	}
}

int main(){
	cin>>m>>k;m/=2;
	rep(i,1,k)cin>>x, a[x]=1;
	for(n=1;n<=m*9;n<<=1);
	rep(i,1,n-1) id[i] = id[i>>1]>>1|(i&1?n>>1:0);
	NTT(a,1);rep(i,0,n-1)a[i]=pw(a[i],m);NTT(a,-1);
	rep(i,0,n) ans = (ans + a[i] * a[i]) % MOD;
	cout<<ans<<endl;
	return 0;
}