
#include "bits/stdc++.h"

using namespace std;

#pragma GCC optimize("Ofast")
typedef long long ll;
#define all(x) x.begin(), x.end()
#define trav(i, x) for(auto &i : x)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define FOR(i, N) for(int i = 0; i < (N); i++)
#define vt vector
#define rs resize


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


string s, t;
const int mxN = 2e5 + 20;



void solve() {
	int n; cin >> n;
	vector<int> a(n);
	vector<int> evens;
	vector<int> odds;

	for(auto &i : a)
		cin >> i;

	for(auto &i: a)
		if(i%2) odds.push_back(i);
		else evens.push_back(i);


	for(auto &i : odds)
		cout << i << " ";
	for(auto &i : evens)
		cout << i << " ";
	cout << "\n";
}

int main() {
	
	
	io();
	int t = 1;
	cin >> t;
	

	auto begin = std::chrono::high_resolution_clock::now();
	while(t--) solve();
	
	
	auto end = std::chrono::high_resolution_clock::now();
	cerr << setprecision(4) << fixed;
	cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	
}