#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

vector<pair<char, int>> d(string s) {
	vector<pair<char, int>> r;
	for(int i=0, j=0; i<s.size(); i=j) {
		for(; j<s.size()&&s[j]==s[i]; ++j);
		r.push_back(make_pair(s[i], j-i));
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int _=0; _<n; ++_) {
		string s, t;
		cin >> s >> t;
		vector<pair<char, int>> v1=d(s), v2=d(t);
		if(v1.size()^v2.size()) {
			cout << "NO\n";
			continue;
		}
		bool ok=1;
		for(int i=0; i<v1.size(); ++i) {
			if(v1[i].first^v2[i].first||v1[i].second>v2[i].second)
				ok=0;
		}
		if(ok)
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}
}