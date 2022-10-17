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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	vl v(n);
	REP(i, n)cin >> v[i];
	ll ans = 0;
	ll tmp = 0;
	REP(i, n - 1) {
		ll d = (v[i] + tmp) / k;
		if (d*k < tmp) {
			d++;
			ans += d;
			tmp = 0;
		}
		else {
			ans += d;
			tmp = v[i] + tmp - d * k;
		}

	}
	ans += (v.back() + tmp + k - 1) / k;
	cout << ans << endl;
}