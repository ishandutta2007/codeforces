
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

bool ispal(string v) {
	string t = v;
	reverse(t.begin(), t.end());
	
	return v == t;
}
void solve() {
	int x = 0, y = 0;
	
	int n; cin >> n;
	vector<int> a(n);
	for(int &i : a) cin >> i;
	
	for(int i = 0; i < n; i++) {
		if(a[i] == 1) {
			if(x==max(x, y)) x++;
			else y++;
		} else if(a[i] == 2) {
			if(x < y) {
				x--;
			} else {
				y--;
			}
		} else if(a[i] == 3) {
			if(x >= y) {
				if(x >= 0) x++;
				else x--;
			} else {
				if(y >= 0) y++;
				else y--;
			}
		}
	}
	
	cout << max(0, x) + max(0, y) << "\n";
}


int main() {
	
	
	
	
	io();
	int t;
	cin >> t;

	auto begin = std::chrono::high_resolution_clock::now();
	while(t--) solve();
	
	
	auto end = std::chrono::high_resolution_clock::now();
	cerr << setprecision(4) << fixed;
	cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	
}