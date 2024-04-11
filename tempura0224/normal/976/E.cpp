#include <bits/stdc++.h>
#define rep(i, n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,x,y;
	cin>>n>>x>>y;
	y=min(n,y);
	vector<pair<ll,ll>> p(n);
	rep(i,n)cin>>p[i].first>>p[i].second;
	vector<int> ord(n);
	rep(i,n)ord[i]=i;
	sort(p.begin(),p.end(),[](auto l, auto r){
		return l.first - l.second > r.first - r.second;
	});
	vector<ll> d(n);
	rep(i,n)d[i]=p[i].first-p[i].second;
	vector<ll> sum(n+1);
	rep(i,n)sum[i+1]=sum[i]+max(d[i], 0ll);
	int idx = y;
	while(idx && d[idx-1]<0)--idx;
	ll ans = 0;
	if(y){
		rep(i,n){
			ll after = max(p[i].first*(1<<x) -p[i].second, 0ll);
			ll before = max(p[i].first - p[i].second, 0ll);
			if(i<idx){
				ans = max(ans, sum[idx]-before+after);
			} else {
				if(y==idx){
					ans = max(ans, sum[idx-1]+after);
				} else {
					ans = max(ans, sum[idx]+after);
				}
			}
		}
	}
	ll s = 0;
	rep(i,n)s+=p[i].second;
	std::cout<<ans+s<<endl;
}