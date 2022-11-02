#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

constexpr ll MOD = 1e9+7;

void run() {
	int n; cin >> n;
	set<int> small, great, neutral;
	ll ans = 1;

	small.insert(INT_MIN);
	great.insert(INT_MAX);

	rep(i, 0, n) {
		string type; cin >> type;
		int x; cin >> x;

		if (type == "ADD") {
			if (x < *small.rbegin()) {
				small.insert(x);
			} else if (x > *great.begin()) {
				great.insert(x);
			} else {
				neutral.insert(x);
			}
		} else {
			if (neutral.count(x)) {
				ans = (ans*2) % MOD;
				each(e, neutral) {
					if (e < x) small.insert(e);
					else if (e > x) great.insert(e);
				}
			} else if (*small.rbegin() == x) {
				small.erase(x);
				each(e, neutral) great.insert(e);
			} else if (*great.begin() == x) {
				great.erase(x);
				each(e, neutral) small.insert(e);
			} else {
				cout << "0\n";
				return;
			}
			neutral.clear();
		}
	}

	ans = (ans * (sz(neutral)+1)) % MOD;
	cout << ans << endl;
}