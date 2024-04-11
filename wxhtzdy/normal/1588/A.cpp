#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	function<void()> solve = [&]() {
		int N;
		cin >> N;

		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		vector<int> B(N);
		for (int i = 0; i < N; i++) {
			cin >> B[i];
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		bool ok = true;
		for (int i = 0; i < N; i++) {
			if (B[i] != A[i] && B[i] != A[i] + 1) 
				ok = false;
		}

		cout << (ok ? "YES" : "NO") << "\n";
	};

	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;	
}