#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	long long n;
	cin >> n;
	vector<long long> pf;
	for (long long i = 2; i * i <= n; ++i) {
		if (n % i) continue;
		while (n % i == 0) {
			n /= i;
		}
		pf.push_back(i);
	}
	if (n > 1) {
		pf.push_back(n);
	}
	if (pf.size() > 1 || pf.size() == 0) {
		cout << 1;
	} else 
		cout << pf[0];
}