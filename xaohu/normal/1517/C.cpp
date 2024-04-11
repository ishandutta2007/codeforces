#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int n, p[500][500], cnt[500];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i][i];

	iota(cnt + 1, cnt + n + 1, 1);
	for (int i = 0; i < n; i++) {
		bool was = 0;
		for (int j = 0; i + j < n; j++) {
			int x = p[i + j][j];
			if (cnt[x] == 1) {
				was = 1;
				continue;
			}
			if (!was)
				p[i + j + 1][j] = x;
			else
				p[i + j][j - 1] = x;
			cnt[x]--;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			cout << p[i][j] << " ";
		cout << endl;
	}
	return 0;
}