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

constexpr int MAX_N = 12;
constexpr int MAX_K = 105;

int n, m, q;
Vi weights;

int counts[1<<MAX_N];
int wu[1<<MAX_N];
int ans[1<<MAX_N][MAX_K];

int readSeq() {
	string tmp; cin >> tmp;
	int enc = 0;

	rep(i, 0, sz(tmp)) {
		if (tmp[i] == '1') enc |= 1<<i;
	}
	return enc;
}

void run() {
	cin >> n >> m >> q;

	weights.resize(n);
	each(w, weights) cin >> w;

	rep(i, 0, m) counts[readSeq()]++;

	rep(i, 0, 1<<n) {
		rep(bit, 0, n) if ((~i >> bit) & 1) wu[i] += weights[bit];
		wu[i] = min(wu[i], MAX_K-1);
	}

	rep(t, 0, 1<<n) {
		rep(i, 0, 1<<n) ans[t][wu[t^i]] += counts[i];
		rep(i, 1, MAX_K) ans[t][i] += ans[t][i-1];
	}

	while (q--) {
		int k, t = readSeq();
		cin >> k;
		cout << ans[t][k] << '\n';
	}
}