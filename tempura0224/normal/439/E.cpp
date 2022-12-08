#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


vector<ll> inv,fact,invfact;
void mod_build(int n=101010){
	fact.resize(n+1);
	inv.resize(n+1);
	invfact.resize(n+1);
	fact[0]=inv[0]=invfact[0]=1;
	inv[1]=1;
	rep(i,n){
		fact[i+1]=fact[i]*(i+1)%mod;
		if(i>0)inv[i+1]=mod-inv[mod%(i+1)]*(mod/(i+1))%mod;
		invfact[i+1]=invfact[i]*inv[i+1]%mod;
	}
}
ll perm(int n,int k){
	if(n<0||k<0||k>n)return 0;
	return fact[n]*invfact[n-k]%mod;
}
ll comb(int n,int k){
	if(n<0||k<0||k>n)return 0;
	return (fact[n]*invfact[n-k]%mod)*invfact[k]%mod;
}
ll pow(ll n,ll k){
	ll ret=1;
	while(k){
		if(k&1)ret=ret*n%mod;
		n=n*n%mod;
		k>>=1;
	}
	return ret;
}
int main(){
	mod_build();
	int N = 101010;
	vector<int> meb(101010,1),isprime(101010,1);
	isprime[0]=isprime[1]=0;
	for(ll i=2;i<N;++i){
		if(!isprime[i])continue;
		for(ll j=i; j<N; j+=i){
			isprime[j]=false;
			meb[j]=-meb[j];
			if(j%(i*i)==0)meb[j]=0;
		}
	}
	int q;
	cin>>q;

	while(q--){
		int n,f;
		cin>>n>>f;
		if(f==1){
			cout<<(n==1)<<endl;
			continue;
		}
		ll ans=0;
		rep(i,N){
			if(i==0)continue;
			if(i*i>n)break;
			if(i*i==n){
				ans+=comb(i-1,f-1)*meb[i];
				ans=(ans+mod)%mod;
				break;
			}
			if(n%i==0){
				ans+=comb(i-1,f-1)*meb[n/i];
				ans+=comb(n/i-1,f-1)*meb[i];
				ans=(ans+2*mod)%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}