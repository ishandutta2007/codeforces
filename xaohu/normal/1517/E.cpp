#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int t, n, c[200001];
ll s[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> c[i];
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		if (n == 2) {
			cout << 1 + (c[1] != c[2]) << endl;
			continue;
		}

		ll res = 1;
		ll lim = (accumulate(c + 1, c + n + 1, 0ll) + 1) / 2;

		ll cur = 0;
		for (int i = n; i >= 3; i--) {
			cur += c[i];
			if (cur >= lim)
				break;
			res++;
		}

		for (int start : {0, 1})
			for (int end : {0, 1}) {
				ll S = (end ? c[n] : 0);
				
				int a = 1 + start;
				int b = n - end;

				s[a - 1] = 0;
				for (int i = a; i <= b; i++)
					if (i >= 2)
						s[i] = s[i - 2] + c[i];

				int p[2] = {b - b % 2, b - (b % 2 == 0)};
				for (int i = a; i <= b; i++) {
					S += c[i];
					if (S >= lim)
						break;
					int x = !(i % 2);
					while (S + s[p[x] - 1] - s[i] >= lim)
						p[x] -= 2;
					res += (p[x] - i) / 2 + 1;
					if (i == b && end)
						res--;
				}
			}

		cout << res % 998244353 << endl;
	}
	return 0;
}