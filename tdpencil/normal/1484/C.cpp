#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
const int mxN = 2e5+5;
const int mnN = 1e5+5;
const int grn = 105;
const int grN = 505;
const int griN = 1005;
const int mxGriN= 5005;
const int mxDP = 7005;
int n, m;
void solve() {
	cin >> n >> m;
	map<int, int> fr;
	fr[-1]=0;
	for(int i=1;i<n+1;i++)
		fr[i]=m/2+m%2;

	vector<pair<int, vector<int>>> res;
	for(int i=0;i<m;i++) {
		int x; cin >> x;
		vector<int> b;
		for(int t=0, a;t<x;t++) {
			cin >> a;
			b.push_back(a);
		}
		res.push_back({i, b});
	}

	sort(res.begin(), res.end(), [](const auto a, const auto b) {
			return a.second.size() < b.second.size();
			});
	set<pair<int, int>> s;
	for(auto &e: res) {
		int choice=-1;
		for(int t : e.second) {
			if(fr[t] > fr[choice]) {
				choice=t;
			}
		}
		if(choice == -1 || fr[choice]==0) {
			cout << "NO\n";
			return;
		} else {
			s.insert({e.first, choice});
			fr[choice]--;
		}
	}
	cout << "YES\n";
	for(auto &e: s)
		cout << e.second << " ";
	cout << "\n";

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		//cerr << "Case #" << case_num << ": ";
		solve();
	}
}