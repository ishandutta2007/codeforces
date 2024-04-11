#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 500000;

typedef long long ll;

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

map<int, ll>mp;

map<int, int>id; int num[MAXN + 5], cnt;

ll c[MAXN + 5]; vector<int>vec[MAXN + 5];
void solve() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%lld", &c[i]), vec[i].clear();
	for(int i=1;i<=m;i++) {
		int u, v; scanf("%d%d", &u, &v);
		vec[u].push_back(v);
	}
	for(int i=1;i<=n;i++) num[i] = 0;
	cnt = 0;
	
	for(int i=1;i<=n;i++) {
		id.clear();
		for(int j=0;j<vec[i].size();j++) {
			int p = vec[i][j], q = num[p];
			if( id.count(q) )
				num[p] = id[q];
			else num[p] = id[q] = (++cnt);
		}
	}
	
	mp.clear();
	for(int i=1;i<=n;i++)
		if( num[i] ) mp[num[i]] += c[i];
	
	ll ans = mp.begin()->second;
	for(map<int, ll>::iterator it = mp.begin(); it != mp.end(); it++)
		ans = gcd(ans, it->second);
	
	printf("%lld\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}