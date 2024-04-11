#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e5+10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
LL fac[N],ifac[N],t[N],p[N],T;

LL pw(LL x,int n){
	LL res = 1;
	for(;n;n>>=1,x=x*x%P)if(n&1)res=res*x%P;
	return res;
}
LL C(int x,int y){
	if(y<0||y>x)return 0;
	return fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int main(){
	//freopen("test.in","r",stdin);
	fac[0]=1;
	rep(i,1,N-1)fac[i]=fac[i-1]*i%P;
	ifac[N-1] = pw(fac[N-1], P-2);
	rrep(i,N-2,0)ifac[i]=ifac[i+1]*(i+1)%P;
	
	scanf("%d%lld",&n,&T);
	rep(i,1,n)scanf("%d",t+i);
	LL sum = 0, sumc = 0, num = -1;
	rep(i,1,n){
		sum += t[i];
		if(sum+i<=T){
			p[i]=0;continue;
		}else if(sum>T){
			p[i]=1;continue;
		}
		LL x = sum + i - T - 1, tmp = (sumc * 2 - C(i-1, num) + P) % P;
		rep(j,num+1,x){
			tmp = (tmp + C(i, j)) % P;
		}
		sumc = tmp; num = x;
		p[i] = sumc * pw(2, P-1-i) % P;
	}
	p[n+1] = 1;
	LL ans = 0;
	rep(i,1,n){
		ans = (ans + (p[i+1]-p[i]) * i % P + P) % P;
	}
	printf("%lld\n",ans);
	return 0;
}