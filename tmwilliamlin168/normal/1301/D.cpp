#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	if(k>4*n*m-2*n-2*m) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	vector<pair<int, string>> v;
	for(int i=0; i<n-1; ++i) {
		if(m>1) {
			v.push_back(make_pair(m-1, "RDU"));
			v.push_back(make_pair(m-1, "L"));
		}
		v.push_back(make_pair(1, "D"));
	}
	if(m>1) {
		v.push_back(make_pair(m-1, "R"));
		v.push_back(make_pair(m-1, "L"));
	}
	for(int i=0; i<n-1; ++i)
		v.push_back(make_pair(1, "U"));
	vector<pair<int, string>> u;
	while(k) {
		if(v[0].first*v[0].second.size()<=k) {
			k-=v[0].first*v[0].second.size();
			u.push_back(v[0]);
			v.erase(v.begin());
		} else if(v[0].second.size()<=k) {
			k-=v[0].second.size();
			u.push_back(make_pair(1, v[0].second));
			--v[0].first;
		} else {
			u.push_back(make_pair(1, v[0].second.substr(0, k)));
			k=0;
		}
	}
	cout << u.size() << "\n";
	for(pair<int, string> p : u)
		cout << p.first << " " << p.second << "\n";
}