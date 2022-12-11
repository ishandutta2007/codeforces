#include <bits/stdc++.h>

using namespace std;

#define X first 
#define Y second 
#define FOR(i,L,R) for(auto i=(L);i<=(R);i++)
#define REP(i,L,R) for(auto i=(L);i<(R);i++)

typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;

const int MOD=1e9+7;
const int N=0;

ll rmodulo(ll a1,ll a2,ll mod){
	pll re1=pll(1,0),re2=pll(0,1);
	while (a2){
		ll val=a1/a2;
		pll tmp=pll((re1.X+(mod-re2.X)*val)%mod,(re1.Y+(mod-re2.Y)*val)%mod);
		re1=re2;re2=tmp;
		ll na2=a1-a2*val;
		a1=a2;a2=na2;
		// cout<<re2.X<<" "<<re2.Y<<" "<<a2<<'\n';
	}
	return re1.X;
}

ll solve(ll a1,ll b1,ll a2,ll b2,ll L,ll R){
	if (b1<b2){
		swap(a1,a2);
		swap(b1,b2);
	}
	ll pos=(b1-b2)%a2;
	ll jump=__gcd(a1,a2);
	if (pos%jump) return 0;
	ll mul=rmodulo(a1/jump,a2/jump,a2/jump)*((a2-pos)/jump)%(a2/jump);
	ll st=b1+mul*a1;
	ll cir=a1*a2/jump;
	if (st<L) st+=(L-st+cir-1)/cir*cir;
	// cout<<st<<" "<<cir<<'\n';
	if (st>R) return 0;
	return (R-st)/cir+1;
}
int main(){
	ll a1,b1,a2,b2,L,R;
	cin>>a1>>b1>>a2>>b2>>L>>R;
	cout<<solve(a1,b1,a2,b2,L,R);
}