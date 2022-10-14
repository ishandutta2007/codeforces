#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

inline void solve() {
	int n;
	cin >> n;
	
	vector<ll> A(n);
	
	for(auto &num: A) cin >> num;
	
	sort(A.begin(), A.end());
	
	int ans = 1;
	
	vector<vector<int>> teams;
	for(int i=1; i < n; i++) {
		if(A[i] - A[i-1] <= 1) {
			ans++;
		}
	}
	
	if(ans == 1) {
		cout << ans << '\n';
		return;
	}
	ans=2;
	set<int> s;
	
	for(auto &num: A) s.insert(num);
	
	int dupl = n - s.size();
	
	cout << ans + dupl << "\n";
	
}
struct point {
	double f, s;
};
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}