#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int i = 0;
	for ( ; i + 1 < n && s[i] <= s[i + 1]; ++i);
	cout << s.substr(0, i) + s.substr(i + 1) << '\n';
}