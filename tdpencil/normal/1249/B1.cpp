#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

inline void solve() {
	int n;
	cin >> n;
	
	
	vector<int> A(n);
	
	for(auto &num: A) {
		cin >> num;
	}
	
	
	vector<int> answer(n);
	for(int i=0; i < n; i++) {
		set<int> passed;
		int x = A[i];
		int times = 1;
		while(x != (i+1) && !passed.count(x)) {
			times++;
			passed.insert(x);
			x = A[x-1];
		}
		answer[i]=times;
		
	}
	
	for(auto &num: answer) {
		cout << num << " ";
	}
	cout << '\n';
	
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