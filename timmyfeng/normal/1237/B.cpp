#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> pos(n + 1), b(n);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		pos[a] = i;
	}
	for (auto& i : b) {
		cin >> i;
	}

	int mex = 0;
	int ans = 0;
	vector<bool> done(n);
	for (int i = 0; i < n; ++i) {
		while (mex < n && done[mex]) {
			++mex;
		}
		ans += (mex < pos[b[i]]);
		done[pos[b[i]]] = true;
	}
	cout << ans << "\n";
}