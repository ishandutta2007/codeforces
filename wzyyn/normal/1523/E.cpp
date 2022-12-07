#include<bits/stdc++.h>
using namespace std;

const int N=200005;
const int mo=1000000007;
int fac[N],inv[N];
void init(){
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<N;i++)
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
}
void solve(){
	int n,k,ans=1;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		if (n-1ll*(i-1)*(k-1)>=i){
			int v=1ll*fac[n-(i-1)*(k-1)]*inv[i]%mo*inv[n-(i-1)*(k-1)-i]%mo;
			v=1ll*v*inv[n]%mo*fac[n-i]%mo*fac[i]%mo;
			ans=(ans+v)%mo;
		}
	cout<<ans<<endl;
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}