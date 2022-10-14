#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 8E5;

int st[N], diff[N];

void modify(int p, int l, int r, int i, int x) {
    if (l == r) {
        if (st[p] == 0) {
            diff[p] = 1;
        }
		st[p] += x;
		if (st[p] == 0) {
            diff[p] = 0;
		}
		return;
    }
    int mid = l + r >> 1;
    if (i <= mid) modify(p * 2, l, mid, i, x);
    else modify(p * 2 + 1, mid + 1, r, i, x);
	diff[p] = diff[p * 2] + diff[p * 2 + 1];
}

int query(int p, int l, int r, int ql, int qr) {
	if (l > r || l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) return diff[p];
    int mid = l + r >> 1;
    return query(p * 2, l, mid, ql, qr) + query(p * 2 + 1, mid + 1, r, ql, qr);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n);
    std::vector<int> vec;
	for (int i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
		vec.push_back(x[i]);
	}

	std::sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	int m = (int) vec.size();

    for (int i = 0; i < n; i++) {
		x[i] = std::lower_bound(vec.begin(), vec.end(), x[i]) - vec.begin() + 1;
		modify(1, 0, m, x[i], 1);
    }

    std::vector<int> order(n);
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&](int i, int j) {
		if (y[i] != y[j]) {
			return y[i] < y[j];
		} else {
			return x[i] < x[j];
		}
    });

	i64 ans = 0;
    for (int id = 0; id < n; id++) {
		int i = order[id];
		int ptr = id;
		while (ptr + 1 < n && y[order[ptr + 1]] == y[order[ptr]]) {
			ptr += 1;
		}

		for (int j = id; j <= ptr; j++) {
            int prv = (j == id ? 0 : x[order[j - 1]]);
            i64 L = query(1, 0, m, prv + 1, x[order[j]]);
            i64 R = query(1, 0, m, x[order[j]], m);
            ans += L * R;
		}

        for (int j = id; j <= ptr; j++) {
            modify(1, 0, m, x[order[j]], -1);
        }
        id = ptr;
    }

    std::cout << ans << "\n";

    return 0;
}