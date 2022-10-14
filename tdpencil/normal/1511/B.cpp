
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
	
	
	unsigned a, b, c;
	cin >> a >> b >> c;
	
	ll x = 6, y, z;
	
	while(to_string(x).size() < c) {
		x *= 6;
	}
	
	y = x;
	z = x;
	while(to_string(y).size() < a) {
		y *= 2;
	}
	
	while(to_string(z).size() < b) {
		z *= 3;
	}
	
	cout << y << " " << z << "\n";
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