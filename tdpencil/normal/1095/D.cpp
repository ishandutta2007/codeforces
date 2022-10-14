#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> a;

void check(int l, int r) {
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int nxt = -1;
		if (a[l][0] == r) {
			nxt = a[l][1];
		} else if (a[l][1] == r) {
			nxt = a[l][0];
		} else {
			return;
		}
		ans.push_back(nxt);
		l = r;
		r = nxt;
	}
	for (auto it : ans) {
		cout << it + 1 << " ";
	}
	cout << endl;
	exit(0);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	a = vector<vector<int>> (n, vector<int>(2));
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1];
		--a[i][0];
		--a[i][1];
	}
	
	check(0, a[0][0]);
	check(0, a[0][1]);
	
	assert(false);
	
	return 0;
}