#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
string t;
int main() {
	cin >> n >> m;
	cin >> s >> t;
	vector<int> z(n + 1, 0);
	for (int i = 0; i + n <= m; i++) {
		vector<int> u;
		for (int j = 0; j < n; j++) {
			if (s[j] != t[i + j]) {
				u.push_back(j);
			}
		}
		if (u.size() < z.size()) {
			z.swap(u);
		}
	}
	printf("%d\n", z.size());
	for (int i = 0; i < z.size(); i++) {
		printf("%d%c", z[i] + 1, i == z.size() - 1 ? '\n' : ' ');
	}
	return 0;
}