#include <bits/stdc++.h>
using namespace std;

long long ans, n;

vector < long long > All, A;

long long solve(long long x) {
	long long T = n / x;
	return T * (T - 1) / 2 * x + T;
}

int main() {
	cin >> n;
	for(int i = 1; i * i <= n; ++ i) {
		if(n % i == 0) {
			All.push_back(i);
			All.push_back(n / i);
		}
	}
	sort(All.begin(), All.end());
	All.erase(unique(All.begin(), All.end()), All.end());
	reverse(All.begin(), All.end());
	for(int i = 0; i < (int) All.size(); ++ i) {
		cout << solve(All[i]) << " ";
	}
}