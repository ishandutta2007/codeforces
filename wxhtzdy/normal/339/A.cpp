#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = (int)s.length();
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if(s[i] == '+') {
			continue;
		}
		v.push_back((int)(s[i]-'0'));
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i];
		if(i < (int)v.size() - 1) {
			cout << "+";
		}
	}
}