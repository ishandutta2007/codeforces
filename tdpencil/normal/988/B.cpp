
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
int n, m;
int a[mxN];
ll cnt[11];
string G[1000];
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> G[i];
	
	sort(G, G + n, [&](const string a, const string b) {
		return a.size() < b.size();
	});
	bool works = true;
	for(int i = 0; i < n - 1; i++) {
		bool can = false;
		for(int j = 0; j < G[i + 1].size() - G[i].size() + 1; j++) {
			
			if(G[i+1].substr(j, (int)G[i].size()) == G[i]) {
				can = true;
			}
		}
		works &= can;
	}
	
	if(works) {
		cout << "YES\n";
		for(int i = 0; i < n; ++i) cout << G[i] << "\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	
	
	io();
	int t = 1;
	// cin >> t;
	

	auto begin = std::chrono::high_resolution_clock::now();
	while(t--) solve();
	
	
	auto end = std::chrono::high_resolution_clock::now();
	cerr << setprecision(4) << fixed;
	cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	
}