#include <bits/stdc++.h>
using namespace std;

int n, a[26];
string s, t;
vector<int> ops;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s >> t;
	for(char c : s)
		++a[c-'a'];
	for(char c : t)
		--a[c-'a'];
	for(int i=0; i<26; ++i) {
		if(a[i]) {
			cout << -1;
			return 0;
		}
	}
	for(int i=0; i<n; ++i) {
		if(s[i]!=t[i]) {
			int j=i;
			while(s[++j]!=t[i]);
			for(; j>i; --j) {
				swap(s[j-1], s[j]);
				ops.push_back(j);
			}
		}
	}
	cout << ops.size() << "\n";
	for(int i=0; i<ops.size(); ++i)
		cout << ops[i] << " ";
}