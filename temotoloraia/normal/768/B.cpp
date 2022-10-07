#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=10005;
const ll INF=1e17;
ll n,l,r;
ll nn=1;
ll ans,MAX;
ll x,M;
//  x*2+1=y    x=(y-1)/2
ll f (ll k){
	x=n;
	M=MAX;
	while (1){
		if (x<=1)return x;
		if (k==M/2+1)return x%2;
		x/=2;
		if (k>M/2+1)k-=M/2+1;
		M=(M-1)/2;
	}
}
int main(){
	cin>>n;
	while (nn<=n)nn*=2;
	MAX=nn-1;
	cin>>l>>r;
	for (ll i=l;i<=r;i++){
	ans+=f(i);
	//cout<<i<<" "<<f(i)<<endl;
	}
	cout<<ans<<endl;
    return 0;
}