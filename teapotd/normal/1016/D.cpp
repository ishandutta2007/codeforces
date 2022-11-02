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

constexpr int MAX_N = 100;

int matrix[MAX_N][MAX_N];
Vi rows, cols;

void run() {
	int n, m; cin >> n >> m;
	rows.resize(n);
	cols.resize(m);

	each(x, rows) cin >> x;
	each(x, cols) cin >> x;

	rep(bit, 0, 32) {
		int j = 0;
		rep(i, 0, n) if ((rows[i] >> bit) & 1) {
			while (j+1 < m && !((cols[j] >> bit) & 1)) j++;

			cols[j] ^= 1 << bit;
			rows[i] ^= 1 << bit;
			matrix[i][j] ^= 1 << bit;
		}

		j = 0;
		rep(i, 0, m) if ((cols[i] >> bit) & 1) {
			while (j+1 < n && !((rows[j] >> bit) & 1)) j++;

			rows[j] ^= 1 << bit;
			cols[i] ^= 1 << bit;
			matrix[j][i] ^= 1 << bit;
		}
	}

	each(x, rows) if (x) {
		cout << "NO\n";
		return;
	}

	each(x, cols) if (x) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";

	rep(i, 0, n) {
		rep(j, 0, m) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << endl;
}