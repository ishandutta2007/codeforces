#include <bits/stdc++.h>

using namespace std;

int main() {      
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> v(3);
	for (int i = 0; i < n; i++) {
	 	cin >> a[i];
	 	v[a[i] - 1].push_back(i + 1);
	}
	int x = min(min((int)v[0].size(), (int)v[1].size()), (int)v[2].size());
	cout << x << '\n';
	for (int i = 0; i < x; i++) {
	 	cout << v[0][i] << " " << v[1][i] << " " << v[2][i] << '\n';
  } 
}