#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int mo=1000000007;
const int N=1000005;
int f[N],phi[N];
int g[N],h[N];
int S1(int x){
	return 1ll*x*(x+1)%mo*(mo+1)/2%mo;
}
int S2(int x){
	return 1ll*x*(x+1)%mo*(2*x+1)%mo*(mo+1)/2%mo*(mo+1)/3%mo;
}
void init(){
	For(i,1,N-1) f[i]=(1ll*i*i+1ll*S1(i)*i+mo-S2(i))%mo;
	For(i,1,N-1) phi[i]=i;
	For(i,1,N-1) For(j,2,(N-1)/i) phi[i*j]-=phi[i];;
	For(i,1,N-1) For(j,1,(N-1)/i)
		f[i*j]=(f[i*j]+mo-phi[i]*j)%mo;
	For(i,1,N-1) f[i]=2ll*f[i]%mo;
	For(i,1,N-1) f[i]=(1ll*i*i*i+mo-f[i])%mo;
	For(i,1,N-1) g[i]=1ll*f[i]*i%mo,h[i]=1ll*f[i]*i%mo*i%mo;
	For(i,1,N-1) f[i]=(f[i]+f[i-1])%mo;
	For(i,1,N-1) g[i]=(g[i]+g[i-1])%mo;
	For(i,1,N-1) h[i]=(h[i]+h[i-1])%mo;
}
/*
0.5(n*m+n+m-gcd(n,m))
*/
void solve(){
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	ans=1ll*(n+1)*(m+1)%mo*f[n]%mo;
	ans=(ans+mo-1ll*(n+m+2)*g[n]%mo)%mo;
	ans=(ans+h[n])%mo;
	printf("%d\n",ans);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}