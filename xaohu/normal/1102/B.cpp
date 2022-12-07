#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int n, k, cnt[5000], a[5000], ord[5000];
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[--a[i]]++;
	}
	if (*max_element(cnt, cnt + 5000) <= k) {
		cout << "YES\n";
		iota(ord, ord + n, 0);
		sort(ord, ord + n, [&](int x, int y) {
			return a[x] < a[y];
		});
		for (int i = 0; i < n; i++)
			a[ord[i]] = i % k;
		for (int i = 0; i < n; i++)
			cout << a[i] + 1 << " ";
		cout << endl;
	}
	else
		cout << "NO\n";
	
	return 0;
}