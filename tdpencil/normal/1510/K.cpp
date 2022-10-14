#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t = 1;
	
	while(t--) {
		int n; cin >> n;
		vi a(2 * n);
		for(auto &i : a) {
			cin >> i;
		}
		vi b = a;
		vi c = a;
		int steps[2] = {};
		for(int i = 0; i < 4 * n; i++) {
			if(is_sorted(b.begin(), b.end())) {
				break;
			}
			if(i % 2 == 0) {
				for(int i = 0; i + 1 < 2 * n; i += 2) {
					swap(b[i], b[i+1]);
				}
			} else {
				for(int i = 0; i < n; i++) {
					swap(b[i], b[n + i]);
				}
			}
			++steps[0];
		}
		
		for(int i = 0; i < 4 * n; i++) {
			if(is_sorted(c.begin(), c.end())) {
				break;
			}
			if(i % 2 == 1) {
				for(int i = 0; i + 1 < 2 * n; i += 2) {
					assert(i + 1 < 2 * n);
					swap(c[i], c[i+1]);
				}
			} else {
				for(int i = 0; i < n; i++) {
					swap(c[i], c[n + i]);
				}
			}
			++steps[1];
		}
		if(!is_sorted(c.begin(), c.end()) && !is_sorted(b.begin(), b.end())) {
			cout << -1 << "\n";
			
		} else if(is_sorted(c.begin(), c.end()) && !is_sorted(b.begin(), b.end())) {
			cout << steps[1];
		} else if(!is_sorted(c.begin(), c.end()) && is_sorted(b.begin(), b.end())) {
			cout << steps[0];
		}
		else cout << min(steps[0], steps[1]);
		
	}
}