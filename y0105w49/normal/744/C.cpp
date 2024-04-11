#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const int inf=1e9+99;
const ld eps=1e-10;

const int N=16;
int n;
int r[N],b[N];
char c[N];
vector<pair<int,int> > dp[1<<N];

void init_dp() {
	// for(int m=(1<<n);--m>=0;) dp[m]={};
}
void go(int m,int A,int B) {
	auto &ans=dp[m];
	if(ans.size()) return;
	if(A+B==n) { ans.emplace_back(0,0); return; }
	for(int i=0;i<n;i++) if(!((m>>i)&1)) {
		int AA=A,BB=B;
		pair<int,int> cp={max(r[i]-A,0),max(b[i]-B,0)};
		if(c[i]=='R') ++AA; else
		if(c[i]=='B') ++BB; else
		assert(0);
		// if(!m) printf("on init, cp (%d,%d)\n",cp.fi,cp.se);
		int mm=(m|(1<<i));
		go(mm,AA,BB);
		auto &rec=dp[mm];
		for(auto &Q:rec) ans.emplace_back(Q.fi+cp.fi,Q.se+cp.se);
	}
	sort(ans.begin(),ans.end());
	ans.resize(unique(ans.begin(),ans.end())-ans.begin());
	int z=(int)ans.size();
	vector<pair<int,int> > nans;
	for(int i=0;i<z;i++) {
		if(!i || ans[i].se<nans.back().se) nans.pb(ans[i]);
	}
	ans.clear();
	for(auto &P:nans) ans.pb(P);
}

int main() {
	scanf("%d",&n);
	static char buf[10];
	for(int i=0;i<n;i++) scanf("%s%d%d",buf,r+i,b+i), c[i]=buf[0];
	init_dp();
	go(0,0,0);
	int be=inf;
	for(auto &Q:dp[0]) be=min(be,max(Q.fi,Q.se));
	printf("%d\n",be+n);
}