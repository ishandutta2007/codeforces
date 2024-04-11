#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>

using namespace std;

const int N = (int)1e6 + 1;

void calc(vector<pair<int, int>> &primes, vector<int> &g, int x, int curDiv, int pos) {
	if (pos == primes.size()) {
		if (g[curDiv] != curDiv)
			g[curDiv] = gcd(g[curDiv], x);
		return;
	}
	auto [p, cnt] = primes[pos];
	for (int i = 0; i <= cnt; i++) {
		calc(primes, g, x, curDiv, pos + 1);
		curDiv *= p;
	}
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);

	vector<int> pr(N), g(N);
	for (int i = 1; i < N; i++) pr[i] = i;
	for (int i = 2; i < N; i++) { 
		if (pr[i] == i) {
			if (i * 1LL * i < N) {
				for (int j = i * i; j < N; j += i) {
					pr[j] = i;
				}
			}
		}
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		x = i + 1;
		cin >> x;
		unordered_map<int, int> primesMap;
		for (int j = x; j > 1; j /= pr[j]) {
			++primesMap[pr[j]];
		}
		vector<pair<int, int>> primes(primesMap.begin(), primesMap.end());
		calc(primes, g, x, 1, 0);
	}
	int res = 0;
	for (int i = 1; i < N; i++) {
		if (g[i] == i) res++;
	}
	cout << res - n << endl;
	return 0;
}