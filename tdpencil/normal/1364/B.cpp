
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
	stack<pair<int, int>> st;

	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	deque<int> res;
	res.push_back(a[0]);
	for(int i = 1; i < n - 1; i++) {
		if(a[i] > a[i+1] && a[i] > a[i-1]) res.push_back(a[i]);
		else if(a[i] < a[i+1] && a[i] < a[i-1]) res.push_back(a[i]);
	}

	res.push_back(a[n-1]);
	cout << res.size() << "\n";
	for(int i : res) {
		cout << i << " ";
	}
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