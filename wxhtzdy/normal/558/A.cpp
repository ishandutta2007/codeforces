#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 105;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

int N, X[MX], A[MX];

ll calc(vi a, vi b) {
	int n = sz(a), m = sz(b);
	int x = 0, y = 0; ll sum = 0;
	F0R(i, 1000000) {
		if (i % 2 == 0) {
			if (x == n) break;
			sum += a[x++];
		} else {
			if (y == m) break;
			sum += b[y++];
		}
	}
	return sum;
}

int main() {
	io();
	cin >> N;
	F0R(i, N) cin >> X[i] >> A[i];
	vi ord(N); iota(all(ord), 0);
	sort(all(ord), [&](int i, int j) { return X[i] < X[j]; });
	vi pos, neg;
	for (int i : ord) {
		if (X[i] < 0) neg.pb(A[i]);
		else pos.pb(A[i]);
	}
	reverse(all(neg));
	cout << max(calc(neg, pos), calc(pos, neg)) << '\n';
}