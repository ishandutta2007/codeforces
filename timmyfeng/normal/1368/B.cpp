#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll k;
	cin >> k;

	vector<int> freq(10, 1);
	ll cur = 1;
	while (cur < k) {
		int ndx = min_element(freq.begin(), freq.end()) - freq.begin();
		cur /= freq[ndx];
		++freq[ndx];
		cur *= freq[ndx];
	}

	string ans = "codeforces";
	for (int i=  0; i < 10; ++i) {
		cout << string(freq[i], ans[i]);
	}
	cout << "\n";
}