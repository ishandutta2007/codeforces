#include <iostream>
#include <cstdio>
#include <cstring>

const int ms = 200100;

struct BIT {
	int a[ms];

	void init() {memset(a, 0, sizeof a);};

	int qry(int x) {
		int ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += a[x];
		}
		return ans;
	}

	void upd(int x, int v) {
		for(; x < ms; x += x & -x) {
			a[x] += v;
		}
	}
};

BIT bit[3];
int perm[2][ms];
int ans[ms];

int main() {
	int n;
	std::cin >> n;
	for(int j = 0; j < 2; j++) {
		for(int i = 0; i < n; i++) {
			scanf("%i", &perm[j][i]);
			bit[j].upd(i + 1, 1);
		}
	}
	for(int i = 0; i < n; i++) {
		bit[2].upd(i + 1, 1);
	}
	for(int i = 0; i < n; i++) {
		int rest = n - i;
		bit[0].upd(perm[0][i] + 1, -1);
		bit[1].upd(perm[1][i] + 1, -1);
		int nxt = bit[0].qry(perm[0][i]) + bit[1].qry(perm[1][i]);
		ans[i] = nxt;
	}
	for(int i = n - 1; i >= 0; i--) {
		while(ans[i] >= n - i) {
			ans[i] -= n - i;
			if(i) ans[i - 1]++;
		}
	}
	for(int i = 0; i < n; i++) {
		int l = 1, r = n;
		while(l != r) {
			int mid = (l + r) / 2;
			if(bit[2].qry(mid) >= ans[i] + 1) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		bit[2].upd(l, -1);
		ans[i] = l - 1;
	}
	for(int i = 0; i < n; i++) {
		printf("%i%c", ans[i], i + 1 == n ? '\n' : ' ');
	}
}