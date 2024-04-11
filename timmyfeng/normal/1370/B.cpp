#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> even, odd;
		for (int i = 1; i <= 2 * n; ++i) {
			int a;
			cin >> a;	
			(a % 2 ? even : odd).push_back(i);
		}
		
		for (int i = 0; i < n - 1; ++i) {
			if (even.size() <= 1u) {
				swap(even, odd);
			}
			cout << even.back() << " ";
			even.pop_back();
			cout << even.back() << "\n";
			even.pop_back();
		}
	}
}