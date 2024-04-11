#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int main() {
	vector<bool> prime(N, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i < N; i++) {
		if (prime[i] == false) {
		 	continue;
		}
		for (int j = 2 * i; j < N; j += i) {
		 	prime[j] = false;
		}
	}
	int n;
	cin >> n;
	for (int i = 4; i < n; i++) {
	 	if (prime[i] == false && prime[n - i] == false) {
	 	 	cout << i << " " << n - i;
	 	 	return 0;
	 	}	
	}
}