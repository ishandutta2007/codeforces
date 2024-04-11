#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000005;

int k, n;
int a[N], b[N], pos[N], use[N];

int tr[N];

void insert(int p) {
	while (p < N) {
		tr[p]++;
		p += p & -p;
	}
}

int getsum(int p) {
	int ret = 0;
	while (p) {
		ret += tr[p];
		p -= p & -p;
	}
	return ret;
}

int getsum(int l, int r) {
	return getsum(r) - getsum(l);
}

int main() {
	scanf("%d%d", &k, &n);
	memset(pos, -1, sizeof(pos));
	for (int i = 0; i < k; ++i) {
		scanf("%d", a + i);
		pos[a[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", b + i);
		use[b[i]] = true;
	}
	long long ans = 0;
	set<int> occ;
	occ.insert(-1);
	occ.insert(k);
	for (int i = 1; i <= 1000000; ++i) {
		if (pos[i] == -1) {
			continue;
		}
		if (use[i] == true) {
			occ.insert(pos[i]);
		} else {
			int rb = *occ.upper_bound(pos[i]), lb = *--occ.upper_bound(pos[i]);
			ans += rb - lb - 1 - getsum(lb + 1, rb);
			insert(pos[i] + 1);
		}
	}
	cout << ans << endl;
	return 0;
}