#include <bits/stdc++.h>

using namespace std;

int main() {                                 
	int tt;
	cin >> tt;
	while (tt--) {
	 	int n;
	 	cin >> n;
	 	vector<int> a(n);
	 	map<int, int> m;
	 	for (int i = 0; i < n; i++) {
	 	  cin >> a[i];
	 	  m[a[i]]++;
	 	}
	 	int res = 0;
	 	for (int i = 0; i < n; i++) {
	 	 	res += m[a[i]] - 1;
	 	 	m[a[i]] = 1;
		}
		cout << n - res << endl;
	}
}