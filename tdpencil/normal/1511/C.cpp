
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
struct fentree {
	int N;
	vector<ll> q;
	fentree(int _S) {
		N = _S;
		q.resize(N+1);
	}

	void add(int idx, ll val) {
		for(++idx; idx <= N; idx += idx & -idx)
			q[idx] += val;
	}
	void rangeAdd(int l, int r, ll val) {
		add(r+1, -val);
		add(l, val);
	}
	ll get(int idx) {
		ll sum = 0;
		for(++idx; idx > 0; idx -= idx & -idx)
			sum += q[idx];
		return sum;
	}
	ll rangeQuery(int l, int r) {
		if(l == 0) {
			return get(r);
		} else {
			return get(r) - get(l-1);
		}
	}
};

int pos[51];
void solve() {
	int n, q;
	cin >> n >> q;
	
	vt<int> a(n);
	for(int &i: a) cin >> i;
	
	set<int> s;
	
	vt<pair<int, int>> b;
	for(int i = 0; i < n; i++) {
		if(!s.count(a[i])) {
			b.push_back({a[i], i+1});
			pos[a[i]]=i+1;
		}
		s.insert(a[i]);
	}
	for(auto &e: b) {
		cerr << e.first << " " << e.second << "\n";
	}
	assert(b.size() <= 50);
	while(q--) {
		int x; cin >> x;
		int f;
		for(auto &i : b) {
			if(i.first == x) f=i.second;
		}
		int idx;
		for(int i = 0; i < b.size(); i++) {
			if(b[i].first == x) idx=i;
		}
		cout << f << " ";
		for(auto &i: b) {
			if(i.second < f) {
				i.second++;
			}
		}
		b.erase(b.begin() + idx);
		b.insert(b.begin(), {x, 1});
		
		
	}
	
	
}


int main() {
	
	
	
	
	io();
	int t = 1;
	

	auto begin = std::chrono::high_resolution_clock::now();
	while(t--) solve();
	
	
	auto end = std::chrono::high_resolution_clock::now();
	cerr << setprecision(4) << fixed;
	cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	
}