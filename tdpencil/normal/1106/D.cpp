
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

template<class T>
void print(T t) {
	cout << t << "\n";
}

template<class T>
void print(vector<T> &t) {
	for(auto &e: t)
		cout << e << " ";
	cout << "\n";
}

template<class T>
void print(vector<pair<T, T>> &t) {
	for(auto &e: t)
		cout << e.first << " " << e.second << "\n";
}

string s, t;
const int mxN = 2e5 + 20;



bool vis[mxN];
vector<int> adj[mxN];
vector<int> res;
priority_queue<int, vector<int>, greater<int>> pq;
void solve() {
	int n; cin >> n;
	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		--x, -- y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vis[0]=1;
	pq.push(0);

	while(pq.size()) {
		int least = pq.top();
		pq.pop();
		res.push_back(least + 1);
		for(int ed : adj[least]) {
			if(!vis[ed]) {
				vis[ed]=1;
				pq.push(ed);
			}
		}
	}

	print(res);
	
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