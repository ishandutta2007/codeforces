#include <bits/stdc++.h> 
using namespace std;

const int MX = 1024;

bool bad[MX];

bool qry(int a) {
	cout << "? " << a + 1 << endl;
	char res;
	cin >> res;
	return res == 'Y';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int ans = n;
	int len = k == 1 ? 1 : k / 2;
	int m = n / len;

	for (int i = 1; i < m; ++i) {
		for (int j = 0; j < i && j + i < m; ++j) {
			for (int k = j; k < m; k += i) {
				for (int l = k * len; l < (k + 1) * len; ++l) {
					if (!bad[l] && qry(l)) {
						bad[l] = true;
						--ans;
					}
				}
			}
			cout << 'R' << endl;
		}
	}
	cout << "! " << ans << endl;
}