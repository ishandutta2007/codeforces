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
const int mxN = 2e5;

const int mod = 1e9+7;



void solve() 
{
	ll x, y; cin >> x >> y;

	vector<int> a(6), b(6);
	while(x % 2 == 0) {
		x /= 2;
		a[2]++;
	}

	while(x % 3 == 0) {
		x /= 3;
		a[3]++;
	}

	while(x % 5 == 0) {
		x /= 5;
		a[5]++;
	}

	while(y %2 == 0) {
		y /= 2;
		b[2]++;
	}

	while(y % 3 == 0) {
		y /= 3;
		b[3]++;
	}

	while(y % 5 == 0) {
		y /= 5;
		b[5]++;
	}

	if(x != y) {
		cout << -1 << "\n";
		return;
	}


	int ans = abs(a[2] - b[2]) + abs(a[3] - b[3]) + abs(a[5] - b[5]);

	cout << ans << "\n";
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