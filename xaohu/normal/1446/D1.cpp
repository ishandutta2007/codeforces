#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

const int N = 444000;

int n, a[N], cnt[N], lst[N], res;
 
int main() {
	cin >> n;
	rep(i, 1, n) cin >> a[i], cnt[a[i]]++;
	int big = max_element(cnt + 1, cnt + 101) - cnt;
	rep(j, 1, 100) {
		if (j == big) continue;
		rep(j, 0, 2 * n) lst[j] = 1e9;
		int bil = 0;
		rep(i, 1, n) {
			if (lst[bil + n] == 1e9)
				lst[bil + n] = i - 1;
			if (a[i] == big)
				bil++;
			if (a[i] == j)
				bil--;
			res = max(res, i - lst[bil + n]);
		}
	}
	cout << res << endl;
	return 0;
}