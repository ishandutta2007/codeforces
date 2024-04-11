#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll bit[200010];
void add(int x, ll a) {
	for (int i = x; i < 200010; i += i & -i) bit[i] += a;
}
ll sum(ll x) {
	ll ret = 0;
	for (int i = x; i > 0; i -= i & -i) ret += bit[i];
	return ret;
}

ll bit2[200010];
void add2(int x, ll a) {
	for (int i = x; i < 200010; i += i & -i) bit2[i] += a;
}
ll sum2(ll x) {
	ll ret = 0;
	for (int i = x; i > 0; i -= i & -i) ret += bit2[i];
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, k, m;
	cin >> n >> k >> m;
	vector<vector<pair<pll, ll>>> l(n), r(n + 1);
	vector<pair<pll, pll>> v(m);
	REP(i, m) {
		ll a, b, c, p;
		cin >> a >> b >> c >> p;
		a--;
		v[i] = { {p,c},{a,b } };
	}
	sort(ALL(v));
	REP(i, m) {
		ll p = v[i].first.first, c = v[i].first.second;
		l[v[i].second.first].push_back({ {p,c},i });
		r[v[i].second.second].push_back({ {p,c},i });
	}
	ll ans = 0;
	REP(i, n) {
		REP(j, l[i].size()) {
			add(l[i][j].second + 1, l[i][j].first.first*l[i][j].first.second);
			add2(l[i][j].second + 1, l[i][j].first.second);
		}
		REP(j, r[i].size()) {
			add(r[i][j].second + 1, -r[i][j].first.first*r[i][j].first.second);
			add2(r[i][j].second + 1, -r[i][j].first.second);
		}
		ll a = -1, b = m - 1;
		while (b - a > 1) {
			int mid = (a + b) / 2;
			if (sum2(mid + 1) >= k) b = mid;
			else a = mid;
		}
		ll tmp = sum(b + 1);
		ll tmp2 = sum2(b + 1);
		ans += sum(b + 1) - max(0ll, (tmp2 - k)*v[b].first.first);

	}
	cout << ans << endl;
}