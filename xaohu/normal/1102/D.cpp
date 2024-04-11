#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int n, cnt[3];
string s;
int main() {
	cin >> n >> s;
	for (char c : s)
		cnt[c - '0']++;
	int m = n / 3;

	for (int i = 0; i < n; i++) {
		int c = s[i] - '0';
		if (cnt[c] > m) {
			for (int j = 0; j < c; j++)
				if (cnt[j] < m) {
					cnt[j]++;
					cnt[c]--;
					s[i] = (char)('0' + j);
					break;
				}
		}
	}

	for (int i = n - 1; 0 <= i; i--) {
		int c = s[i] - '0';
		if (cnt[c] > m) {
			for (int j = 2; c < j; j--) {
				if (cnt[j] < m) {
					cnt[j]++;
					cnt[c]--;
					s[i] = (char)('0' + j);
					break;
				}
			}
		}
	}
	
	cout << s << endl;
	return 0;
}