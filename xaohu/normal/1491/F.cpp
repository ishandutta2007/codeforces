#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int n;

int query(vector<int> v, int a) {
	cout << "? " << sz(v) << " " << 1 << endl;
	for (auto e : v)
		cout << e << " "; 
	cout << endl;
	cout << a << endl;
	cin >> a;
	return a;
}

void solve() {
	cin >> n;
	vector<int> all = {1};
	rep(i, 2, n + 1) {
		if (query(all, i) == 0) {
			all.push_back(i);
			continue;
		}
		int l = 1, r = i - 1;
		while (l < r) {
			int m = (l + r) / 2;
			all.resize(m);
			iota(all.begin(), all.end(), 1);
			if (query(all, i))
				r = m;
			else
				l = m + 1;
		}
		vector<int> res;
		rep(j, 1, l)
			res.push_back(j);
		rep(j, l + 1, i)
			res.push_back(j);
		rep(j, i + 1, n + 1)
			if (!query({i}, j))
				res.push_back(j);
		cout << "! " << sz(res) << " ";
		for (auto e : res)
			cout << e << " ";
		cout << endl;
		return;
	}	
}	

int main() {
	int T;
	cin >> T;
	while (T--) 
		solve();
	return 0;
}