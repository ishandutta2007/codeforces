#include <bits/stdc++.h>

using namespace std;

mt19937 mt(124);

bool used[1000010];

bool prime(int x) {
	return !used[x];
}

void init() {
	used[0] = true;
	used[1] = true;
	for (int i = 2; i <= 1000000; i++) {
		if (!used[i]) {
			for (int j = 2 * i; j <= 1000000; j += i)
				used[j] = true;
		}
	}
}

const int N = 1010;
int deg[N];
int totdeg;
vector <pair<int, int>> edges;

void add(int x, int y) {
	assert(x != y);
	totdeg += 1;
	edges.push_back(make_pair(x, y));
	deg[x]++;
	deg[y]++;
}

bool solve(int n) {
	for (int i = 1; i <= n; i++)
		deg[i] = 0;
	totdeg = 0;
	edges.clear();

	for (int i = 1; i < n; i++) {
		add(i, i + 1);
	}
	add(1, n);

	set <int> additional;

	while (!prime(totdeg)) {
		int x = mt() % n + 1, y = mt() % n + 1;
		if (x == y)
			continue;
		if (x > y)
			swap(x, y);
		if (additional.count(x) || additional.count(y))
			continue;
		if (y == x + 1 || (x == 1 && y == n))
			continue;
		additional.insert(x);
		additional.insert(y);
		add(x, y);
	}
	for (int i = 1; i <= n; i++) {
		assert(prime(deg[i]));
	}
	return true;
}

void output() {
	printf("%lu\n", edges.size());
	for (auto e: edges)
		printf("%d %d\n", e.first, e.second);
}

int main() {
	init();
	int n;
	scanf("%d", &n);
	solve(n);
	output();
}