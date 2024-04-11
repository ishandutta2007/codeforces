#include <bits/stdc++.h>
using namespace std;
int r[100020];
int a[100020];
int b[100020];
string s[100020];
bool cmp(int x, int y) {
	return (long long)a[x] * b[y] > (long long)a[y] * b[x];
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		r[i] = i;
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++) {
			if (s[i][j] == 's') {
				a[i]++;
			}
			if (s[i][j] == 'h') {
				b[i]++;
			}
		}
	}
	sort(r, r + n, cmp);
	string z;
	for (int i = 0; i < n; i++) {
		z += s[r[i]];
	}
	int ss = 0;
	long long ans = 0;
	for (int i = 0; i < z.size(); i++) {
		if (z[i] == 'h') {
			ans += ss;
		} else {
			ss++;
		}
	}
	printf("%lld\n", ans);
}