#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e3;
int n, k;
string s;
vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> s;
	int s2=0;
	while(1) {
		v.push_back({});
		for(int i=0; i+1<n; ++i) {
			if(s[i]=='R'&&s[i+1]=='L') {
				v.back().push_back(i);
				++s2;
			}
		}
		for(int j : v.back())
			swap(s[j], s[j+1]);
		if(v.back().empty()) {
			v.pop_back();
			break;
		}
	}
	if(k<v.size()||k>s2) {
		cout << -1;
		return 0;
	}
	for(int i=0; i<v.size(); ++i) {
		while(v[i].size()>1&&k>v.size()) {
			--k;
			cout << "1 " << v[i].back()+1 << "\n";
			v[i].pop_back();
		}
		cout << v[i].size();
		for(int j : v[i])
			cout << " " << j+1;
		cout << "\n";
	}
}