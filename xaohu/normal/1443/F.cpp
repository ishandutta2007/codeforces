#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int>
typedef long long ll;	
using namespace std;

const int N = 200111;

int n, k, a[N], b[N], when[N], pos[N], T;

int main() { 
	cin >> T;
	while (T--) {
		cin >> n >> k;
		rep(i, 1, n + 1)
			when[i] = 0;
		rep(i, 1, n + 1)
			cin >> a[i], pos[a[i]] = i;
		rep(i, 1, k + 1) {
			cin >> b[i];
			when[b[i]] = i;
		}
		a[0] = a[n + 1] = 0;
		when[0] = n + 1;
		int res = 1;
		rep(i, 1, k + 1) {
			int p = pos[b[i]];
			res = res * (2 - (when[a[p + 1]] > when[a[p]]) - (when[a[p - 1]] > when[a[p]])) % 998244353;
		}
		cout << res << "\n";
	}
	return 0;
}