#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;	
using namespace std;

int k, n, m, a[111], b[111];

void solve() {
	cin >> k >> n >> m;
	rep(i, 0, n)
		cin >> a[i];
	rep(i, 0, m)
		cin >> b[i];
	vector<int> res;
	int pa = 0, pb = 0;
	a[n] = b[m] = 1024;
	while (pa < n || pb < m) {
		if (pa < n && a[pa] == 0) {
			k++; 
			pa++;
			res.push_back(0);
			continue;
		}

		if (pb < m && b[pb] == 0) {
			k++;
			pb++;
			res.push_back(0);
			continue;
		}

		if (a[pa] < b[pb]) {
			if (k < a[pa]) {
				cout << "-1\n";
				return;
			}
			res.push_back(a[pa++]);
		}

		else {
			if (k < b[pb]) {
				cout << "-1\n";
				return;
			}
			res.push_back(b[pb++]);
		}
	}

	for (auto x : res)
		cout << x << " ";
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}