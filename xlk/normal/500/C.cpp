#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a[2000], b[2000], v[2000];
vector<int> s;
long long ans;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		if (v[b[i]] == 0) {
			s.push_back(b[i]);
			v[b[i]] = 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == b[i]) {
				rotate(s.begin(), s.begin() + j, s.begin() + j + 1);
				break;
			}
			ans += a[s[j]];
		}
	}
	cout << ans << endl;
	return 0;
}