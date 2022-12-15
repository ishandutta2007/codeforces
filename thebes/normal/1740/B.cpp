#include "bits/stdc++.h"
 
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
// const ll mod = 998244353;
typedef pair<double,double> pdd;
const int mn = 1e6+10;
const int SZ = 700;
const double pi = acos(-1.);
mt19937 rng(time(0));


void solve() {
	int n;
	vector<pii> v;
	cin>>n;
	ll sb=0,sa=0;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v.emplace_back(a,b);
		if(a<b)swap(a,b);
		sb+=b;
		sa=max(sa,ll(a));
	}
	printf("%lld\n",sa*2+sb*2);
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
	int tc=1;
	cin >> tc;
	for(int tcc=1;tcc<=tc;tcc++){
		//printf("Case #%d: ",tcc);
		solve();
	}
}