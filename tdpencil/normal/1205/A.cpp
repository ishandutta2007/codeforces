#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
#define pb push_back
#define all(x) x.begin(),x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define f first
#define s second
#define ar array
#define vt vector
#define ub upper_bound
#define lb lower_bound
#define nl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vt vector
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vt<pl>
#define vb vector<bool>
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)

ll n, m, k;
const int mxN=1e6,M=998244353;
const ll inf = 8e18;
template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;
template<typename K> using dq = deque<K>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



void solve(int test_case = 0) {
	int n; cin >> n;
	if(n&1^1) {
		cout << "NO" << nl;
		return;
	}
	cout << "YES" << nl;
	vi c(2 * n);
	iota(all(c), 1);
	reverse(all(c));

	vi res(2 * n);

	for(int i = 0; i < n; ++i) {
		
		res[i] = c.back();
		c.pop_back();
		res[i + n] = c.back();
		c.pop_back();
		if(i&1^1)
			swap(res[i], res[i+n]);
	}

	rep(i,0,2*n) {
		cout << res[i] << " ";
	}
	cout << "\n";
}

int main()
{
    //setup();
	cin.tie(0)->sync_with_stdio(0);
    //precalc();
    int T = 1;
    // cin >> T;

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}