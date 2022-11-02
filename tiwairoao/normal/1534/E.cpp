#include <bits/stdc++.h>

typedef unsigned int ui;

const int N = 500;

int n, k, t; bool tag[N + 5];
ui query(int l, int r) {
	int p = k - (r - l + 1);
	assert (0 <= p && p < l && l <= r);
	putchar('?');
	for (int i = l; i <= r; i++) printf(" %d", i), tag[i] ^= 1;
	for (int i = 1; i <= p; i++) printf(" %d", i), tag[i] ^= 1;
	puts(""), fflush(stdout);

	ui a; scanf("%u", &a); return a;
}
ui query2(int l, int r) {
	int p = t - (r - l + 1);
	assert (0 <= p && p < l && l <= r);

	static bool vis[N + 5];
	std::vector<int>vec, vec2;
	for (int i = l; i <= r; i++) vec.push_back(i), vis[i] = true;
	for (int i = 1; i <= p; i++) vec.push_back(i), vis[i] = true;
	assert ((int)vec.size() == t);

	int q = 1;
	for (int i = 1; i <= k - (t >> 1); i++) {
		while (vis[q]) q++; vec2.push_back(q++);
	}

	ui ret = 0, a;
	putchar('?');
	for (int i = 0; i < (t >> 1); i++) printf(" %d", vec[i]), tag[vec[i]] ^= 1;
	for (auto x : vec2) printf(" %d", x), tag[x] ^= 1;
	puts(""), fflush(stdout);
	scanf("%u", &a), ret ^= a;

	putchar('?');
	for (int i = (t >> 1); i < t; i++) printf(" %d", vec[i]), tag[vec[i]] ^= 1;
	for (auto x : vec2) printf(" %d", x), tag[x] ^= 1;
	puts(""), fflush(stdout);
	scanf("%u", &a), ret ^= a;

	for (auto x : vec) vis[x] = false;
	return ret;
}

int main() {
	scanf("%d%d", &n, &k);

	if (n % k == 0) {
		ui ans = 0;
		for (int i = 1; i <= n; i += k) ans ^= query(i, i + k - 1);
		printf("! %u\n", ans), fflush(stdout); 
	} else if (k & 1) {
		int r = n % k;
		if (r & 1) {
			if (n > (k << 1)) {
				ui ans = query(1, k);
				while (n - k > (k << 1)) ans ^= query(n - k + 1, n), n -= k;
				ans ^= query(k + 1, (n + k + 1) >> 1) ^ query((n + k + 3) >> 1, n);
				printf("! %u\n", ans), fflush(stdout); 
			} else {
				t = ((n - k) << 1);
				if (n % t == 0) {
					ui ans = 0;
					for (int i = 1; i <= n; i += t) ans ^= query2(i, i + t - 1);
					printf("! %u\n", ans), fflush(stdout); 
				} else if (n > (t << 1)) {
					ui ans = query2(1, t);
					while (n - t > (t << 1)) ans ^= query2(n - t + 1, n), n -= t;
					ans ^= query2(t + 1, (n + t + 1) >> 1) ^ query2((n + t + 3) >> 1, n);
					printf("! %u\n", ans), fflush(stdout);
				} else {
					ui ans = query2(1, t);
					t = n - t;
					ans ^= query2(n - t + 1, n);
					printf("! %u\n", ans), fflush(stdout);
				}
			}
		} else {
			ui ans = query(1, k);
			while (n - k > k) ans ^= query(n - k + 1, n), n -= k;
			ans ^= query(k + 1, (n + k + 1) >> 1) ^ query((n + k + 3) >> 1, n);
			printf("! %u\n", ans), fflush(stdout);
		}
	} else {
		if (n & 1) {
			puts("-1"), fflush(stdout);
			return 0;
		} else {
			ui ans = query(1, k);
			while (n - k > (k << 1)) ans ^= query(n - k + 1, n), n -= k;
			ans ^= query(k + 1, (n + k + 1) >> 1) ^ query((n + k + 3) >> 1, n);
			printf("! %u\n", ans), fflush(stdout); 
		}
	}
	for (int i = 1; i <= n; i++) assert (tag[i]);
}