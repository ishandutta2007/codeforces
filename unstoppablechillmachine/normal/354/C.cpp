#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 1e6 + 10;
int cnt[N], cnt2[N];
mt19937 rnd(time(0));
signed main() {
	ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &it : a) {
		cin >> it;
	}
	shuffle(all(a), rnd);
	for (int i = 1; i <= n; i++) {
		int x = a[i - 1];
		//cin >> x;
		int y = max(1, x - k);
		int curmax = (int)sqrt(x), T = (int)sqrt(x);
		for (int j = T; j >= 1; j--) {
			int L = (y + j - 1) / j, R = x / j;
			if (R != L - 1) {
				cnt[j]++;
			}
			L = max(L, curmax + 1);
			if (L <= R) {
				cnt2[L]++;
				cnt2[R + 1]--;
			}
			curmax = max(curmax, R);
		}
		if (clock() * 1.0 / CLOCKS_PER_SEC > 0.97) {
			n = i;
			break;
		}
	}	
	int cr = 0;
	for (int i = 1; i <= 1e6; i++) {
		cr += cnt2[i];
		cnt[i] += cr;
	}
	for (int i = 1e6; i >= 1; i--) {
		if (cnt[i] == n) {
			cout << i << '\n';
			exit(0);
		}
	}
}