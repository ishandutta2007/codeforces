#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> pt(n);
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		++pt[a - 1];
	}
	cout << *min_element(pt.begin(), pt.end()) << '\n';
}