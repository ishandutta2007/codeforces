/*
ID: tdpenci1
LANG: C++
TASK: beads
*/
#include "bits/stdc++.h"

using namespace std;

#pragma optimize ("Ofast")
typedef long long ll;
#define all(x) x.begin(), x.end()
#define trav(i, x) for(auto &i : x)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define FOR(i, N) for(int i = 0; i < (N); i++)
#define vt vector
const ll mod = 1e9 + 7;
const int mxA = 1e7;




void io(const string s="") {
	if(s != "") {
		freopen((s+".in").c_str(), "r", stdin);
		freopen((s+".out").c_str(), "w", stdout);
	} else {
		ios_base::sync_with_stdio(false); cin.tie(0);
	}
}

int main() {
	io();
	int t;
	cin >> t;

	while(t--) {
		int n, k;
		cin >> n >> k;

		if(2*k >= n ) {
			cout << -1 << "\n";
		} else {
			int next1 = 1;
			int next2 = n;
			int res = k;
			set<int> used;
			for(int i = 1; i <= n; i++) used.insert(i);
			while(k--) {

				if(next1 != next2) cout << next1 << " " << next2 << " ";
				else cout << next1 << " ";
				used.erase(next1);
				if(next1 != next2) used.erase(next2);
				next1++;
				next2--;
			}

			while(used.size()) {
				cout << *used.begin() << " ";
				used.erase(used.begin());
			}
			cout << "\n";
		}
	}
}