#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int T, n, l, r, S[20][N];
void m() {
	cin >> l >> r;
	int ans = 1e9;
	for(int i = 0; i < 20; ++ i) {
		ans = min(ans, S[i][r] - S[i][l - 1]);
	}
	cout << ans << endl;
}

int main() {
	for(int t = 0; t < 20; ++ t) {
		for(int i = 1; i < N; ++ i)
		S[t][i] = (S[t][i - 1] + (!((i >> t) & 1)));
	}
	int c;
	for(cin >> c; c --;) m();
}