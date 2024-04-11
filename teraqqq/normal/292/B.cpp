#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5+7;

int n, m, a[N], z = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		a[u-1]++, a[v-1]++;
	}

	sort(a, a+n);
	vector<string> ans = {
		"unknown topology",
		"bus topology",
		"ring topology",
		"star topology"
	};

	if(n == m + 1) {
		bool ok = a[0] == 1 && a[1] == 1;
		for(int i = 2; i < n && ok; ++i)
			if(a[i] != 2) ok = false;
		if(ok) z = 1;
	}

	if(n == m) {
		bool ok = true;
		for(int i = 0; i < n && ok; ++i)
			if(a[i] != 2) ok = false;
		if(ok) z = 2;
	}

	if(n == m + 1) {
		bool ok = true;
		for(int i = 0; i < n-1 && ok; ++i)
			if(a[i] != 1) ok = false;
		if(a[n-1] != m) ok = false;
		if(ok) z = 3;
	}

	cout << ans[z];
}