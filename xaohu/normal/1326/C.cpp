#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

const int P = 998244353;

int n, k, p, lst = -1;
ll res1, res2 = 1;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	rep(i, 0, n) {
		cin >> p;
		if (p >= n - k + 1) {
			if (lst != -1)
				res2 = res2 * (i - lst) % P;
			res1 += p;
			lst = i;
		}
	}
	cout << res1 << " " << res2 << endl;	
	return 0;
}