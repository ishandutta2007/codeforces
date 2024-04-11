#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;
const LL MOD = 998244353;
const int N = 2010;

LL inv[N<<1], fac[N], ifac[N], now[N<<1], b[N<<1], n, k, l, ans=0;

LL pw(LL x, int n){
	LL res=1;
	for(;n;n>>=1,x=x*x%MOD)if(n&1)res=res*x%MOD;
	return res;
}
LL C(int a, int b){
	return fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;
}

void mul1(LL a[], int n){
	rep(i,0,n<<1)b[i]=a[i];
	a[0]=0;a[1]=(b[0]<<1)%MOD;
	rep(j,2,n<<1)a[j]=( -(b[j-2]<<1) + (b[j-1]<<1) + (MOD<<2) ) % MOD;
}
void mul2(LL a[], int n){
	rep(i,0,n<<1)b[i]=a[i];
	a[0]=b[0];a[1]=( -(b[0]<<1)+b[1]+(MOD<<2) ) % MOD;
	rep(j,2,n<<1)a[j]=( (b[j-2]<<1) - (b[j-1]<<1) + b[j] + (MOD<<2) ) % MOD;
}
void div(LL a[], int n){
	memset(b,0,sizeof b);
	rep(i,0,n<<1)b[i]=MOD-a[i+1]*inv[2]%MOD;
	repr(i,n<<1,0)a[i]=b[i+1]%MOD,b[i]+=b[i+1];
}

int main(){
	cin>>n>>k>>l;
	fac[0]=1;
	rep(i,1,n) fac[i] = fac[i-1]*i%MOD;
	ifac[n] = pw(fac[n],MOD-2);
	repr(i,n-1,0) ifac[i] = ifac[i+1]*(i+1)%MOD;
	rep(i,1,n+1<<1) inv[i] = pw(i,MOD-2);
	
	now[0] = 1;
	rep(i,1,n) mul1(now,i);
	repr(t,n,k){
		LL anst = 0;
		rep(i,0,n<<1) anst = (anst + now[i]*inv[i+1]) % MOD;
		ans = (ans + anst * C(n,t)) % MOD;
		div(now,n);mul2(now,n);
	}
	cout<<(ans+MOD)%MOD*l%MOD<<endl;
}