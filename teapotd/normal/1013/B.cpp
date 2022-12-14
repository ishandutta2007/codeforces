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

void run() {
	int n, x; cin >> n >> x;

	Vi elems(n), counts(100001);

	each(e, elems) {
		cin >> e;
		counts[e]++;
	}

	each(c, counts) if (c >= 2) {
		cout << "0\n";
		return;
	}

	each(e, elems) if ((e&x) != e && counts[e&x] > 0) {
		cout << "1\n";
		return;
	}

	counts.assign(sz(counts), 0);
	each(e, elems) if (++counts[e&x] >= 2) {
		cout << "2\n";
		return;
	}

	cout << "-1\n";
}