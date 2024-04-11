#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int n; 
		cin >> n;
		vector <int> a(n), b(n), c;
		for (auto &it : a) cin >> it;
		for (auto &it : b) cin >> it;
		FOR(i, n) if (b[i] == 0) c.push_back(a[i]);
		sort(c.begin(), c.end());
		reverse(c.begin(), c.end());
		int k = 0;
		FOR(i, n) 
			if (!b[i])
				a[i] = c[k++];
		FOR(i, n) cout << a[i] << " ";
		cout << endl;
	}
		
	return 0;
}