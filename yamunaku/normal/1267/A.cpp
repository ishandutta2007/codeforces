#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>

using namespace std;

using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const ll INF = (1e+18)+100;
#define rep(i, n) for(int i=0;i<n;++i)
#define repl(i, l, n) for(int i=l;i<n;++i)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;

using speP = pair<LP, ll>;
void solve() {
	int n; cin >> n;
	vector<speP> v(n);
	rep(i, n) {
		ll a, b, l; cin >> a >> b >> l;
		v[i] = { {a,b},l };
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	ll cur = v[0].first.first;
	int loc = 0;
	priority_queue<LP,vector<LP>,greater<LP>> q;
	while (true) {
		//cout << loc <<" "<<q.size()<< endl;
		while (loc<n&&cur >= v[loc].first.first) {
			q.push({ v[loc].second,v[loc].first.second });
			loc++;
		}
		if (q.empty()) {
			if (loc == n)break;
			cur = v[loc].first.first;
			continue;
		}
		LP p = q.top();
		ll dif = p.second - cur;
		if (loc < n) {
			dif = min(dif, v[loc].first.first - cur);
		}
		ll score = dif / p.first;
		if (score <=0) {
			if (cur + p.first > p.second) {
				//cout << "!" << cur << p.first << p.second << endl;
				q.pop(); continue;
			}
			else {
				ans++;
				ll ri = cur + p.first;
				int memo = loc;
				while (loc < n&&v[loc].first.first <= cur + p.first) {
					//q.push({ v[loc].second,v[loc].first.second });
					ri = min(ri, v[loc].first.first + v[loc].second);
					loc++;
				}
				loc = memo;
				cur = ri;
			}
		}
		else {
			ans += score;
			cur += score * p.first;
		}
		//cout << ans << " " << cur <<" "<<q.size()<< endl;
	}
	cout << ans << endl;

}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}