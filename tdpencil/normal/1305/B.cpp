#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector
#define pb push_back
#define ar array

const int mxN=2e5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
  	
	string s;
	cin >> s;
	int n = s.size();

	vector<int> prefix_amount(n);
	for (int i = 0; i < n; i++) {
		prefix_amount[i] = s[i] == '(' ? 1 : 0;
		if(i)
		{
			prefix_amount[i] += prefix_amount[i-1];
		}
	}
	vector<int> suffix_amount(n);
	for (int i = n - 1; ~i; i--) {
		suffix_amount[i] = s[i] == ')' ? 1 : 0;
		if(i + 1 < n)
		{
			suffix_amount[i] += suffix_amount[i + 1];
		}
	}
	int max_removed = 0;
	for (int i = 0; i < n; ++i) {
		max_removed = max(max_removed, min(suffix_amount[i], prefix_amount[i]));
	}
	vector<int> ans;
	int overGood=max_removed,overBad=max_removed;
	for (int i = 0; i < n; i++) {
		if(overGood>0) {
			if(s[i] == '(') {
				ans.push_back(i);
				overGood--;
			}
		}
	}
	for (int i = n -1; i >= 0; i--) {
		if(overBad>0) {
			if(s[i] == ')') {
				ans.push_back(i);
				overBad--;
			}
		}
	}
	sort(ans.begin(), ans.end());
	if(ans.empty()) {
		cout << 0 << "\n";
	} else {
		cout << 1 << "\n";
		cout << ans.size() << "\n";
		for (int &i : ans) {
			cout << i+1 << " ";
		}
		cout << "\n";
	}
}