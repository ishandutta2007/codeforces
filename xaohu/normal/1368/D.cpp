#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int n, cnt[20];
ll res = 0;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	cin >> n;
	rep(i, 0, n) {
		int a;
		cin >> a;
		rep(j, 0, 20)
			if (a >> j & 1)
				cnt[j]++;
	}
	rep(i, 0, n) {
		ll x = 0;
		rep(j, 0, 20)
			if (cnt[j]) {
				x += 1 << j;
				cnt[j]--;
			}
		res += x * x;
	}
	cout << res << "\n";
	return 0;
}