#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;

long long calc(int n, int d) {
	long long k = n / d;
	return (1 + n - d + 1) * k / 2;
}

int main() {
	scanf("%d", &n);
	vector<long long> ans;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			ans.push_back(calc(n, i));
			ans.push_back(calc(n, n / i));
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0; i < (int)ans.size(); ++i) {
		cout << ans[i];
		if (i + 1 == ans.size()) {
			cout << endl;
		} else {
			cout << ' ';
		}
	}
	return 0;
}