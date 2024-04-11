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
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int sum = 0, cnt_good = 0;
		bool kek = false;
		for (auto it : s) {
			sum += it - '0';
			if ((it - '0') % 2 == 0) {
				cnt_good++;
			}
			if (it == '0') {
				kek = true;
			}
		}
		if (kek && sum % 3 == 0 && cnt_good > 1) {
			cout << "red\n";
		}
		else {
			cout << "cyan\n";
		}
	}
}