#include "bits/stdc++.h"

using namespace std;

#pragma GCC optimize("Ofast")
typedef long long ll;

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

void io(const string s="") {
	if(s != "") {
		freopen((s+".in").c_str(), "r", stdin);
		freopen((s+".out").c_str(), "w", stdout);
	} else {
		ios_base::sync_with_stdio(false); cin.tie(0);
	}
}
ll pow(ll x, ll y) {
	if(y == 0)
		return 1;

	ll mid = pow(x, y / 2);
	if(y&1)
		return mid * mid * x;
	
	return mid * mid;
}
const int mxN = 2e6;

const int mod = 1e9+7;




int lpf[mxN + 1];

ll factors(int X) {
	map<ll, ll> cnt;
	while(X > 1) {
		int p = lpf[X];
		X /= lpf[X];
		cnt[p]++;
	}

	ll ans = 1;
	for(auto i : cnt) {
		ans *= (i.second + 1);
	}
	return ans;
}
void solve() {
	for(ll i = 2; i <= mxN; i++) {
		if(!lpf[i]) {
			lpf[i] = i;
			for(ll j = 2 * i; j <= mxN; j += i) {
				lpf[j] = i;
			}
		}
	}

	ll a, b, c;
	cin >> a >> b >> c;
	ll res = 0;
	ll md = 1<<30;
	for(ll i = 1; i <= a; i++) {
		for(ll j = 1; j <= b; j++) {
			for(ll k = 1; k <= c; k++) {
				res += factors(i * j * k);
				res %= md;
			}
		}
	}
	cout << res << "\n";
}
int main() {
	
	
	io();
	int t = 1;
	// cin >> t;
	

	auto begin = std::chrono::high_resolution_clock::now();
	while(t--) solve();
	
	
	auto end = std::chrono::high_resolution_clock::now();
	cerr << setprecision(4) << fixed;
	cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	
}