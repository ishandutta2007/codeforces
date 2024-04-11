
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
void solve() {
	cin >> n >> m;
	
	int ans = 0;
	
	for(int i = 0; i < n; ++i) cin >> a[i];
	
	for(int i = 0; i < n; ++i) ++cnt[a[i]];
	
	for(int i = 1; i <= 10; ++i) {
		for(int j = i + 1; j <= 10; ++j) {
			ans += cnt[i] * cnt[j];
		}
	}
	
	cout << ans << "\n";
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