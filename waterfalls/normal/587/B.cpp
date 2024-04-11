#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;

int n,k;
ll l;
int a[1000013];
map<int,int> comp;
vector<pair<int,int> > has;

const int MOD = 1e9+7;

int main() {
	scanf("%d%lld%d",&n,&l,&k);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		comp[a[i]]+=1;
	}
	has.push_back(MP(0,0));
	for (auto it: comp) has.push_back(it);
	int sz = comp.size();
	vector<vector<int> > dp(sz+1,vector<int>(k+1));
	for (int i=0;i<=sz;i++) dp[i][0] = 1;
	for (int i=1;i<=sz;i++) for (int j=1;j<=k;j++) {
		dp[i][j] = (dp[i-1][j]+(ll) has[i].B*dp[i][j-1])%MOD;
	}
	for (int i=1;i<=sz;i++) for (int j=1;j<=k;j++) {
		dp[i][j] = (dp[i][j]+dp[i][j-1])%MOD;
	}
	int ans = 0;
	ll blocks = l/n;
	for (int x=1;x<=k;x++) {
		if (l<x*n) continue;
		ans = (ans+(ll) (dp[sz][x]-dp[sz][x-1])*((blocks-x+1)%MOD))%MOD;
	}
	for (int i=0;i<l%n;i++) {
		int where = lower_bound(has.begin(),has.end(),MP(a[i],0))-has.begin();
		int num = k;
		if (blocks+1<k) num = blocks+1;
		ans = (ans+dp[where][num-1])%MOD;
	}
	if (ans<0) ans+=MOD;
	printf("%d\n",ans);

	return 0;
}