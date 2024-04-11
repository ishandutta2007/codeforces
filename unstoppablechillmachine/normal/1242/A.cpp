#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> srt;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			srt.pb(i);
			srt.pb(n / i);
		}
	}
	sort(all(srt));
	srt.resize(unique(all(srt)) - srt.begin());
	if (SZ(srt) == 0) {
		cout << n << '\n';
		exit(0);
	}
	for (int i = 0; i < SZ(srt); i++) {
		for (int j = i + 1; j < SZ(srt); j++) {
			if (srt[j] % srt[i] != 0) {
				cout << 1 << '\n';
				exit(0);
			}
		}
	}
	cout << srt[0] << '\n';
}