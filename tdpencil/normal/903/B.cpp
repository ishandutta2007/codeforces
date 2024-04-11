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
	int h, a, c; scanf("%d%d%d", &h, &a, &c);
	int x, y; scanf("%d%d", &x, &y);
	
	// greedy sol is to attack as long as the health - y > 0
	vector<bool> willattack;
	while(x > 0) {
		if(h < y + 1 && x > a) {
			willattack.push_back(0);
			h += (c - y);
		} else {
			willattack.push_back(1);
			x -= a;
			h -= y;
		}
	}
	
	cout << willattack.size() << "\n";
	for(bool move : willattack) {
		if(move) {
			puts("STRIKE");
		} else {
			puts("HEAL");
		}
	}
}
int main() {
	
	
	// io();
	int t = 1;
	// cin >> t;
	

	auto begin = std::chrono::high_resolution_clock::now();
	while(t--) solve();
	
	
	auto end = std::chrono::high_resolution_clock::now();
	cerr << setprecision(4) << fixed;
	cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	
}