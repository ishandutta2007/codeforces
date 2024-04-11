#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

long long x, k;

#define div DIV

vector<long long> div;

int n;

vector<long long> ans;

const int BAR = 100000;

void solve(long long n, long long k) {
	if (n == 1) {
		ans.push_back(1);
		return;
	}
	if (k == 0) {
		ans.push_back(n);
		return;
	}
	vector<long long>divs;
	for (int i = 0; i < (int)div.size() && div[i] <= n; ++i) {
		if (n % div[i] == 0) {
			divs.push_back(div[i]);
		}
	}
	if (divs.size() == 2) {
		for (int i = 0; i < k && ans.size() < BAR; ++i) {
			ans.push_back(1);
		}
		if (ans.size() < BAR) {
			ans.push_back(n);
		}
	} else {
		for (int i = 0; i < (int)divs.size(); ++i) {
			if (ans.size() < BAR) {
				solve(divs[i], k - 1);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> x >> k;
	if (k == 0) {
		cout << x << endl;
		return 0;
	}
	for (long long i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			div.push_back(i);
			if (x / i != i) {
				div.push_back(x / i);
			}
		}
	}
	sort(div.begin(), div.end());
	for (int i = 0; i < (int)div.size(); ++i) {
		if (ans.size() < BAR) {
			solve(div[i], k - 1);
		}
	}
	for (int i = 0; i < (int)ans.size(); ++i) {
		cout << ans[i] << (i != (int)ans.size() - 1 ? ' ' : '\n');
	}
	return 0;
}