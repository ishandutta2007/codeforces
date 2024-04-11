#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

int n, ans;
long long s;
multiset<int> d;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	rep(i, 1, n) {
		int x;
		cin >> x;
		if (x >= 0) {
			ans++;
			s += x;
		}
		else {
			if (s + x >= 0) {
				ans++;
				s += x;
				d.insert(x);
			}
			else if (!d.empty() && *d.begin() < x) {
				s += x - *d.begin();
				d.erase(d.begin());
				d.insert(x);
			}
		}
	}
	cout << ans << "\n";		
	return 0;
}