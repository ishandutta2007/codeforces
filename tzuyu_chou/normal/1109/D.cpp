#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e6+1,tzuyu=1e6;
const ll mod=1e9+7;
ll f[N];
ll inf[N];
int n,m;
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
void twice(){
	f[0]=1;
	for(int i=1; i<=tzuyu ;i++) f[i]=f[i-1]*i%mod;
	inf[tzuyu]=pw(f[tzuyu],mod-2);
	for(int i=tzuyu; i>=1 ;i--) inf[i-1]=inf[i]*i%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	twice();
	ll ans=0;
	for(int i=0; i<=min(n-3,m-1) ;i++){
		ll ways=f[m-1]*inf[i]%mod*inf[m-i-1]%mod*f[n-2]%mod*inf[n-2-i]%mod*(i+2)%mod*pw(n,n-i-3)%mod*pw(m,n-i-2)%mod;
		ans=(ans+ways)%mod;
	}
	if(n-2<=m-1){
		ll ways=f[m-1]*inf[n-2]%mod*inf[m-n+1]%mod*f[n-2]%mod;
		ans=(ans+ways)%mod;
	}
	cout << ans << endl;
}