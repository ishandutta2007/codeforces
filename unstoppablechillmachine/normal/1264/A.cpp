#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		map<int, int> cnt;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		vector<int> srt;
		auto it = --cnt.end();
		int kek = 0;
		while ((kek + it->S) * 2 <= n) {
			srt.pb(it->S);
			kek += it->S;
			it--;
		}
		//cout << kek << ' ' << SZ(srt) << '\n';
		if (SZ(srt) < 3) {
			cout << "0 0 0\n";
			continue;
		}
		int ptr = 1, sum = srt[1];
		while (ptr + 1 < SZ(srt) && sum <= srt[0]) {
			sum += srt[++ptr];
		}
		if (sum > srt[0] && kek - sum - srt[0] > srt[0]) {
			cout << srt[0] << ' ' << sum << ' ' << kek - sum - srt[0] << '\n';
		}
		else {
			cout << "0 0 0\n";
		}
	}
}