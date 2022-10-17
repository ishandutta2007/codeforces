#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second
  
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string s;
		int n;
		cin >> n;
		cin >> s;
		bool can = false;
		vector<int> color(n);
		for (int i = 0; i < 10; i++) {
			bool ok = true;
			int prv1 = -1, prv2 = -1;
			for (int j = 0; j < n; j++) {
				int cur = s[j] - '0';
				if (cur < i) {
					if (prv1 > cur) {
						ok = false;
						break;	
					}
					prv1 = cur;
					color[j] = 1;
				}
				else if (cur == i) {
					if (prv2 <= cur) {
						color[j] = 2;
						prv2 = cur;
					}
					else {
						if (prv1 > cur) {
							ok = false;
							break;
						}
						prv1 = cur;
						color[j] = 1;
					}
				}
				else {
					if (prv2 > cur) {
						ok = false;
						break;
					}
					prv2 = cur;
					color[j] = 2;
				}
			}
			if (ok) {
				can = true;
				for (int j = 0; j < n; j++) {
					cout << color[j];
				}
				cout << '\n';
				break;
			}
		}
		if (!can) {
			cout << "-\n";
		}
	}  
}