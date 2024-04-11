#include <bits/stdc++.h>

const int N = 300000;

char ans[N + 5]; int a[N + 5], cnt[N + 5], n;
bool check1() {
	for (int i = 1; i <= n; i++) if (cnt[i] > 1) return false;
	return true;
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) cnt[i] = 0, ans[i] = '0'; ans[n + 1] = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[a[i]]++;
	
	if (check1()) ans[1] = '1';
	for (int i = 1, l = 1, r = n; i < n; i++) {
		if (!cnt[i]) break;
		ans[n - i + 1] = '1';
		if (cnt[i] > 1) break;
		if (a[l] == i) l++;
		else if (a[r] == i) r--;
		else break;
	}
	puts(ans + 1);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}