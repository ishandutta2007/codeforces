#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
#define double long double
typedef long long ll;	
using namespace std;
int T, n, k;

int main() { 
	cin >> T;
	while (T--) {
		cin >> n >> k;
		vector<int> old(20);
		rep(i, 0, n) {
			vector<int> cur(20), num(20);
			int x = i;
			rep(b, 0, 20) {
				num[b] = x % k;
				x /= k;
			}
			rep(b, 0, 20)
				cur[b] = (old[b] + (i % 2 == 0 ? 1 : -1) * num[b] + k) % k;
			int ask = 0;
			int p = 1;
			rep(b, 0, 20) {
				ask += p * cur[b];
				p *= k;
			}
			cout << ask << endl;
			int r;
			cin >> r;
			if (r)
				break;
			old = num;
			if (i % 2 == 1)
				for (auto& x : old)
					x = (k - x) % k;
		}
	}
	return 0;
}