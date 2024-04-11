#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

unordered_map<ull,int> dp[70];
int nim_val(int x,ull m=0) {
	if(!x) return 0;
	++x;
	// cerr<<"m first "<<m<<endl;
	m &= ~((m>>x)<<x);
	// cerr<<"m after "<<m<<endl;
	--x;
	if(dp[x].count(m)) return dp[x][m];
	int &ans=dp[x][m];

	vector<int> recs;
	for(int i=1;i<=x;i++) {
		if((m>>i)&1) continue;
		recs.pb(nim_val(x-i, m|(1<<i)));
	}
	sort(recs.begin(),recs.end());
	recs.resize(unique(recs.begin(),recs.end())-recs.begin());
	recs.pb(-1);
	for(int y=0;;y++) {
		if(recs[y]!=y) return ans=y;
	}
	assert(0);
}

int32_t main() {
	int n; scanf("%d",&n);
	int Z=0;
	for(;n--;) {
		int s; scanf("%d",&s);
		int y=nim_val(s);
		// cerr<<s<<": "<<y<<endl;
		Z^=y;
	}
	cout<<(Z ? "NO":"YES")<<endl;
	// cerr<<dp.size()<<endl;
}