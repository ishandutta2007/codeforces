#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
long long n;
int k;
vector<long long> a;
int main() {
	cin >> n >> k;
	for (int i = 1; (long long)i * i <= n; i++) {
		if (n % i == 0) {
			a.push_back(i);
			if (n / i != i) {
				a.push_back(n / i);
			}
		}
	}
	sort(a.begin(), a.end());
	if (k > a.size()) {
		printf("-1\n");
	} else {
		cout << a[k - 1] << endl;
	}
	return 0;
}