#include <bits/stdc++.h>

const int N = 2000;

std::vector<std::pair<int, int> >e; int n;
void adde(int u, int v) {
	e.push_back(std::make_pair(u, v));
}
void print() {
	assert ((int)e.size() == n - 1);
	puts("!");
	for (auto k : e) printf("%d %d\n", k.first, k.second);
	fflush(stdout);
}

int d[N + 5], a[N + 5];
void query(int x) {
	printf("? %d\n", x), fflush(stdout);
	for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
	assert (d[x] == 0);
}

int main() {
	scanf("%d", &n);

	int c[2] = {}; query(1);
	for (int i = 1; i <= n; i++) {
		a[i] = d[i], c[a[i] & 1]++;
		if (d[i] == 1) adde(1, i);
	}

	if (c[0] > c[1]) {
		for (int i = 2; i <= n; i++) if (a[i] & 1) {
			query(i);
			for (int j = 2; j <= n; j++) if (d[j] == 1) adde(i, j);
		}
	} else {
		for (int i = 2; i <= n; i++) if (!(a[i] & 1)) {
			query(i);
			for (int j = 2; j <= n; j++) if (d[j] == 1) adde(i, j);
		}
	}
	
	print();	
}