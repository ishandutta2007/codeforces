#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int mo=1000000007;
const int N=200005;
int fac[N],inv[N];
void init(){
	inv[0]=inv[1]=fac[0]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<N;i++)
		inv[i]=1ll*inv[i-1]*inv[i]%mo; 
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
}
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
void solve(){
	int n,k,g=0,e=0,a=1;
	scanf("%d%d",&n,&k);
	if (n&1) e=1; else g=1;
	for (int i=0;i<n;i+=2) e=(e+C(n,i))%mo;
	for (int i=1;i<=n;i++) a=2ll*a%mo;
	int ans=0,p=1;
	for (int i=1;i<=k;i++){
		ans=(1ll*ans*a+1ll*p*g)%mo;
		p=1ll*p*e%mo;
	}
	ans=(ans+p)%mo;
	cout<<ans<<endl;
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}