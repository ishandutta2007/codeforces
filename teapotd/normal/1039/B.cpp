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

mt19937 rnd(int(std::chrono::system_clock::now().time_since_epoch().count()));

void run() {
	ll n, k; cin >> n >> k;

	auto ask = [&](ll begin, ll end) {
		cout << begin+1 << ' ' << end << endl;

		string s;
		cin >> s;

		if (s == "Yes") {
			if (begin+1 == end) exit(0);
			return true;
		} else if (s == "No") {
			return false;
		}
		exit(0);
	};

	ll begin = 0, end = n;

	while (true) {
		if (end-begin < 42) {
			ll i = begin + (rnd() % (end-begin));
			ask(i, i+1);
		} else {
			ll mid = (begin+end) / 2;
			if (ask(begin, mid)) {
				end = mid;
			} else {
				begin = mid;
			}
		}

		begin -= k;
		end += k;
		begin = max(begin, 0ll);
		end = min(end, n);
	}
}