#include <bits/stdc++.h>

using namespace std;

int main() { 
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	map<int, int> m;
	for (int i = 0; i < n; i++) {
	 	cin >> a[i] >> b[i];
	 	m[b[i]]++;
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += m[a[i]];
	}
	cout << res;
}