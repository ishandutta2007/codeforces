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

bool allowed[705][705];
bool dp[705][705][2]; // [begin][end][isLeft]

int getGCD(int a, int b) {
	if (a < b) swap(a, b);
	while (b != 0) {
		int x = a%b;
		a = b;
		b = x;
	}
	return a;
}

void run() {
	int n; cin >> n;
	Vi seq(n);
	each(x, seq) cin >> x;

	rep(i, 0, n) rep(j, 0, n) allowed[i][j] = getGCD(seq[i], seq[j]) > 1;
	rep(i, 0, n) allowed[n][i] = allowed[i][n] = 1;

	rep(i, 0, n+1) {
		dp[i][i][0] = dp[i][i][1] = true;
	}

	auto compute = [&](int begin, int end, bool isLeft) {
		int g = (isLeft ? end : begin-1);
		if (g < 0) g = n;
		dp[begin][end][isLeft] = false;

		rep(i, begin, end) {
			if (allowed[i][g] && dp[begin][i][1] && dp[i+1][end][0]) {
				dp[begin][end][isLeft] = true;
				break;
			}
		}
	};

	rep(len, 1, n+1) {
		rep(begin, 0, n-len+1) {
			compute(begin, begin+len, 0);
			compute(begin, begin+len, 1);
		}
	}

	cout << (dp[0][n][0] ? "Yes\n" : "No\n");
}