
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
const int mxN = 1e5 + 20;
int n, m;
int a[mxN];
bool ne[mxN];
void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	
	int mx = *max_element(a, a+n);
	for(int i = 0; i < n; ++i) ne[i]=a[i]==mx;
	
	int cur = 0;
	int ans = 0;
	
	for(int i = 0; i < n; ++i) {
		if(ne[i]) {
			cur++;
			ans = max(ans, cur);
		} else {
			cur = 0;
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