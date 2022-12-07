#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
const int N = 200000;
int t, n, a[N], b[N];
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			b[i] = -1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			--a[i];
			if (b[a[i]] == -1) {
				b[a[i]] = i;
			}
		}
		vector<int> s, e;
		for (int i = 0; i < n; i++) {
			if (b[i] != -1)
				continue;
			int u = i;
			while (b[a[u]] == u)
				u = a[u];
			s.push_back(i);
			e.push_back(u);
		}
		if (e.size() > 0) {
			if (e.size() > 1 || s[0] != e[0])
				for (int i = 0; i < e.size(); i++)
					a[e[i]] = s[(i + 1) % s.size()];
			else {
				a[b[a[e[0]]]] = e[0];
			}
		}
		cout << n - e.size() << endl;
		for (int i = 0; i < n; i++)
			assert(a[i] != i);
		for (int i = 0; i < n; i++)
			cout << a[i] + 1 << " ";
		cout << endl;
	}
	return 0;
}