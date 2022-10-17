#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef double K;
constexpr int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define X first
#define Y second

constexpr K C = 2.71;

mt19937 rng(123);
#define losuj(a, b) uniform_real_distribution<long double>(a, b)(rng)

void solve() {
	int n, m;
	cin >> n >> m;
	vi myl(n);
	int ja = 0;
	FOR(i, 0, m) {
		string s;
		cin >> s;
		// int ile = *min_element(myl.begin(), myl.end());
		K jed = 0, zer = 0;
		FOR(j, 0, n) {
			if(myl[j] * 1.1 > ja) continue;
			zer += (s[j] == '0');
			jed += (s[j] == '1');
		}
		int rak, odp = losuj(0, jed + zer) > zer;
		cout << odp << endl;
		cin >> rak;
		ja += (odp != rak);
		FOR(j, 0, n) myl[j] += (s[j] - '0' != rak);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin >> tt;
	// FOR(te, 0, tt) {
	// 	// cout << "Case #" << te + 1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}