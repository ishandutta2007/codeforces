#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ld TAU=2*acos(-1);
const ld eps=1e-7;
const int inf=1e9+99;
const ll linf=1e18+88;



const int N=1<<20;
bool isp[N];
vector<int> ps;
const int P=1e9+7;

ll phi(ll n) {
	ll x=n;
	for(int p:ps) {
		if(ll(p)*p>n) break;
		if(!(n%p)) {
			x/=p;
			x*=p-1;
			for(;!(n%p);) n/=p;
		}
	}
	if(n>1) x/=n, x*=n-1;
	return x;
}

ll F(ll n,ll k) {
	if(n==1) return 1;
	if(k==1 || k==2) return phi(n);
	return F(phi(n),k-2);
}

int32_t main() {
	isp[2]=1;
	for(int p=3;p<N;p+=2) isp[p]=1;
	ps.pb(2);
	for(int p=3;p<N;p+=2) {
		if(!isp[p]) continue;
		ps.pb(p);
		for(int x=p+p;x<N;x+=p) isp[x]=0;
	}

	ll n,k; cin>>n>>k;
	cout<<F(n,k)%P<<endl;
}