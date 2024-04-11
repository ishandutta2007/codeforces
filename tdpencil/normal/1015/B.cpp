
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define ar array

const int mxN = 1e5 + 5;


random_device rd;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

vector<int> p[26];

int nextPost(string v, char x, int p) {
	for(int i = p; i < int(v.size()); i++)
		if(v[i]==x)
			return i;


	return -1;
}
void solve() {
	int n; cin >> n;
	string s, t;
	cin >> s >> t;
	assert(s.size() == t.size());
	for(int i = 0; i < n ; i++) {
		p[s[i] - 'a'].push_back(i);
	}
	vector<int> res;

	for(int i = 0; i < n; i++) {
		int nextPos = nextPost(s, t[i], i);
		int j = nextPos;
		bool found = 0;
		while(j > 0 && j != i) {
			swap(s[j-1], s[j]);
			res.push_back(j);
			j--;
		}
		if(j == i && s[i] == t[i])
			found = 1;
		if(!found)
			cout << -1 << "\n";
		if(!found)
			return;
	}
	cout << res.size() << "\n";
	for(auto &e: res)
		cout << e << " ";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin >> t;
	int i = 1;
	while(t--) {
		solve();
		++i;
	}
}