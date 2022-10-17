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
	int n;
	cin >> n;
	map<string, set<int>> mp;
	vector<string> v(n);
	REP(i, n) {
		cin >> v[i];
		REP(j, v[i].size()) {
			FOR(k, 1, v[i].size() - j + 1) {
				mp[v[i].substr(j, k)].insert(i);
			}
		}
	}
	int q;
	cin >> q;
	REP(i, q) {
		string s;
		cin >> s;
		cout << mp[s].size() << " ";
		if (mp[s].empty())cout << "-" << endl;
		else cout << v[*mp[s].begin()] << endl;
	}
}