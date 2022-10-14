#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	while(tt--) {
		int n, k;
		cin >> n >> k;

		if(3 * k > n) {
			cout << -1 << "\n";
			return 0;
		}
		int other = n - 2 * k;
		for(int kk = 1; kk <= k; kk++)
			for(int i = 0; i < 2; i++)
				cout << kk << " ";
		int cur = 0;
		while(other > 0) {
			cout << (cur % k) + 1 << " ";
			++cur;
			--other;
		}


		cout << endl;
	}
}