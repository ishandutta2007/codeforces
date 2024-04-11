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

void run() {
	int n, m = -1; cin >> n;
	Vi elems(n);

	each(e, elems) {
		cin >> e;
		m = max(m, e);
	}

	if (m == 0) {
		cout << "YES\n";
		rep(i, 0, n) cout << "1 ";
		cout << '\n';
		return;
	}

	int good = -1;

	if (elems.back() < elems[0]) {
		good = 0;
	} else {
		rep(i, 1, n) {
			if (elems[i-1] < elems[i]) {
				good = i;
				break;
			}
		}
	}

	if (good < 0) {
		cout << "NO\n";
		return;
	}

	vector<ll> A(n);
	A[good] = elems[good];

	rep(i, 1, n) {
		int cur = (good-i+n) % n;
		int prev = (cur-1+n) % n;
		int next = (cur+1) % n;

		ll k = (elems[prev] - elems[cur]) / A[next];
		A[cur] = (k+1)*A[next] + elems[cur];
	}

	cout << "YES\n";
	each(x, A) cout << x << ' ';
	cout << '\n';
}