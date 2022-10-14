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
bool dp[101][200001];
bool contains_odd(vector<int> nums) {
	// bool works = false;
	for(auto &i : nums)
		if(i&1)
			return 1;

	return 0;
}
void run_case() {
	int N; cin >> N;
	vector<int> A(N);
	for(auto &a: A)
		cin >> a;

	dp[0][0]=1;
	for(int i = 1; i <= N; i++) {
		//2e5 * 1e2 -> 2e7
		for(int j = 0; j <= 200000; j++) {
			dp[i][j] = dp[i - 1][j];
			if(j - A[i - 1] >= 0) {
				dp[i][j] |= dp[i - 1][j - A[i - 1]];
			}
		}
	}

	ll S = accumulate(A.begin(), A.end(), 0);
	if(S%2) {
		cout << 0 << "\n";
		return;
	}
	if(!dp[N][S >> 1]) {
		cout << 0 << "\n";
		return;
	}

	while(!contains_odd(A)) {
		for(auto &i : A)
			i /= 2;
	}

	for(int i = 1; i <= N; i++) {
		if(A[i - 1] % 2) {
			cout << 1 << "\n";
			cout << i << "\n";
			return;
		}
	}

	assert(false);

}
int main() {
	
	
	io();
	int t = 1;
	// cin >> t;
	

	auto begin = std::chrono::high_resolution_clock::now();
	while(t--) run_case();
	
	
	auto end = std::chrono::high_resolution_clock::now();
	cerr << setprecision(4) << fixed;
	cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	
}