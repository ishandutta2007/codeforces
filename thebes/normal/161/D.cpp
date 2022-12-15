#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 5e4+4;
ll cnt[MN][505], n, k, i, j, x, y, ans;
vector<ll> v[MN];

void solve(ll n, ll p){
	cnt[n][0] = 1;
	for(auto x : v[n]){
		if(x == p) continue;
		solve(x, n);
		for(int i=1;i<=k;i++)
			ans += cnt[x][i-1]*cnt[n][k-i];
		for(int i=1;i<=k;i++)
			cnt[n][i] += cnt[x][i-1];
	}
}

int main(){
	for(scanf("%lld%lld",&n,&k),i=0;i<n-1;i++){
		scanf("%lld%lld",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	solve(1,0);
	printf("%lld\n",ans);
	return 0;
}