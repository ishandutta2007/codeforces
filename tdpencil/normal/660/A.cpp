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
const int mxN = 2e7;

const int mod = 1e9+7;




void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int added = 0;
	vector<int> res;
	for(int i = 0; i < n - 1; i++) {
		if(__gcd(a[i], a[i + 1]) != 1) {
			res.push_back(a[i]);
			res.push_back(1);
			++added;
		} else res.push_back(a[i]);
	}
	
	res.push_back(a[n - 1]);
	cout << added << "\n";
	for(int i : res) {
		cout << i << " ";
	}
	
	cout << "\n";
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