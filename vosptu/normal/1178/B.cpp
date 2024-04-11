#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
string S;
int w[N], rw[N];

int main() {
	cin >> S;
	int n = S.size();
	for (int i = 1; i < n; i++) {
		w[i] = w[i - 1];
		if (S[i] == S[i - 1] && S[i] == 'v')
			w[i]++;
	}
	for (int i = n - 2; i >= 0; i--) {
		rw[i] = rw[i + 1];
		if (S[i] == S[i + 1] && S[i] == 'v')
			rw[i]++;
	}
	long long ans = 0;
	for (int i = 1; i < n - 1; i ++) {
		if (S[i] == 'o') {
			ans += 1LL * w[i - 1] * rw[i + 1];
		}
	}
	cout << ans << endl;
}