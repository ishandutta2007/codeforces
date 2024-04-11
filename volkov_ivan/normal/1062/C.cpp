#include <iostream>

using namespace std;

const long long M = 1e9 + 7;
const int MAX_N = 1e5 + 7;
char arr[MAX_N];
int pref[MAX_N];
long long poww[MAX_N];

void pow2() {
	long long ans = 1;
	for (int i = 0; i < MAX_N; i++) {
		long long ans2 = ans - 1;
		if (ans2 < 0) ans2 += M;
		poww[i] = ans2;
		ans = (ans * 2) % M;
	}
}

int main() {	
	//freopen("/Users/ivanvolkov/Desktop/inp.in", "r", stdin);
	int n, q;
	ios_base :: sync_with_stdio(0);
	//cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	pref[0] = 0;
	for (int i = 1; i <= n; i++) pref[i] = (arr[i] - '0') + pref[i - 1];
	pow2();
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		int res = pref[r] - pref[l - 1];
		if (res == (r - l + 1)) {
			cout << poww[r - l + 1] << '\n';
			continue;
		}
		if (res == 0) {
			cout << 0 << '\n';
			continue;
		}
		int zero = (r - l + 1) - res;
		//cout << poww[res] << ' ' << poww[zero] << endl;
		long long ans = (poww[res] * (poww[zero] + 1) + 0) % M;
		cout << ans << '\n';
	}
	return 0;
}