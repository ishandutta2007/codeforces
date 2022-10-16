//#pragma GCC optimize ("O3") 

#include <stdio.h>
#include <bits/stdc++.h>

#define F first
#define S second
#define elif else if

#define INV(x) inv(x, MOD)
#define ADD(a, b) (((ll)(a)+(b))%MOD)
#define SUB(a, b) (((ll)(a)-(b))%MOD)
#define MUL(a, b) (((ll)(a)*(b))%MOD)
#define DIV(a, b) (((ll)(a)*INV(b))%MOD)

using namespace std;
using ll = long long;
using ld = double;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const int INF = 1e8+3;

const ll LINF = 1e18;

const int N = 1e6+7;

int n, k = 58, p[N];

bool ans(istream& is, ostream& os, int x) {
	os << "> " << x << endl; k--;
	int a; is >> a; return a != 0;
}

int ask(istream& is, ostream& os, int i) {
	os << "?  " << i << endl; k--;
	int a; is >> a; return a;
}

int find_max(istream& is, ostream& os) {
	int l = 0, r = 1e9;
	while(l < r) {
		int m = (l+r)/2;
		if(ans(is, os, m)) l = m + 1;
		else r = m;
	}
	return r;
}

void solve(istream& is, ostream& os, bool debug) {
	is >> n;

	iota(p, p+n, 1); mt19937 rnd(clock());
	shuffle(p, p+n, rnd);
	if(debug) copy(p, p+n, ostream_iterator<int>(os, ", ")); cout << endl;

	int max_x = find_max(is, os);
	int d = max_x - ask(is, os, p[0]);
	for(int i = 1; i < n && k != 0; ++i) {
		int r = ask(is, os, p[i]);
		if(r != max_x) d = __gcd(d, max_x-r);
	}

	os << "! " << max_x - d*(n-1) << ' ' << d << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve(cin, cout, false);
}