
#include "bits/stdc++.h"

using namespace std;

#pragma GCC optimize("Ofast")
typedef long long ll;

void io(const string s="") {
	if(s != "") {
		freopen((s+".in").c_str(), "r", stdin);
		freopen((s+".out").c_str(), "w", stdout);
	} else {
		ios_base::sync_with_stdio(false); cin.tie(0);
	}
}
ll pow(ll x, ll y) {
	if(y == 0)
		return 1;

	ll mid = pow(x, y / 2);
	if(y&1)
		return mid * mid * x;
	
	return mid * mid;
}
const int mxN = 2e5;

const long long mod = 1e9+7;

struct priority {
	ll value, weight;
	priority(ll value_, ll weight_) : value(value_), weight(weight_) {}
	priority() : value(0), weight(0) {}
	bool operator <(const priority &x) const {
		return value < x.value;
	}
};


void output_vector(const vector<priority> &pr, bool addone = false) {
	for(int i = 0; i < (int)pr.size(); i++) {
		cout << pr[i].value + bool(addone) << " ";
	}
	cout << "\n";
}

void solve() {
	ll n, m;
	cin >> n >> m;

	vector<vector<priority>> a(n, vector<priority> (m));

	for(int i = 0; i < n; i++) {

		for(int j = 0; j < m; j++) {
			cin >> a[i][j].value;
			a[i][j].weight = j;
		}
	}


	
	for(int i = 0; i < n; i++)
		sort(a[i].begin(), a[i].end());

	// greedy is to add on to the next one

	
	set<pair<int, int>> st;

	for(int i = 0; i < m; i++)
		st.insert({a[0][i].value, i});

	output_vector(a[0]);
	for(int i = 1; i < n; i++) {
		set<pair<int, int>> newST;
		vector<int> res(m);
		for(int j = 0; j < m; j++) {
			// lets add on to the maximum value there is
			assert(!st.empty());
			pair<int, int> toFind = *st.rbegin();
			// reverse order
			
			st.erase(toFind);
			int mn = toFind.first;
			// find max
			res[toFind.second] = a[i][j].value;
			if(a[i][j].value < mn) {
				newST.insert({a[i][j].value, toFind.second});
			} else {
				newST.insert({mn, toFind.second});			}
		}

		for(auto &i : res) {
			cout << i << " ";
		}
		cout << "\n";
		st = newST;
	}



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