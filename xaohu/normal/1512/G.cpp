#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 50;

int ans[N], prime[N], f[N];

int main() {
	ans[1] = 1;
	f[1] = 1;
	for (int i = 2; i < N; i++) {
		if (!prime[i]) {
			ans[i] = i + 1;
			for (int j = i; j < N; j += i)
				prime[j] = i;
		}
		else {
			int x = prime[i];
			while (i % (x * prime[i]) == 0) 
				x *= prime[i];
			if (x < i)	
				ans[i] = ans[x] * ans[i / x];
			else
				ans[i] = ans[i / prime[i]] + x;
		}
		if (ans[i] < N)
			if (!f[ans[i]])
				f[ans[i]] = i;
	}
	int t;
	cin >> t;
	while (t--) {
		int c;
		cin >> c;
		cout << (!f[c] ? -1 : f[c]) << "\n";
	}
	return 0;
}