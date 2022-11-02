#include <bits/stdc++.h>
using namespace std;

const int N = 400010;

int n;
struct Point {
	int x, y;
} p[N];
int sum[N];
bool used[N];

bool cmp(Point a, Point b) {
	return a.y > b.y;
}

void modify(int x, int y) {
	for (; x <= n; x += x & -x)
		sum[x] += y;
}

int query(int x) {
	int ans = 0;
	for (; x; x -= x & -x)
		ans += sum[x];
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	map <int, int> pool;
	for (int i = 1; i <= n; i++) {
		pool[p[i].x] = 0;
	}
	int cnt = 0;
	for (auto it: pool) {
		pool[it.first] = ++cnt;
	}
	for (int i = 1; i <= n; i++) {
		p[i].x = pool[p[i].x];
	}
	sort(p + 1, p + n + 1, cmp);
	unsigned long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j + 1 <= n && p[j + 1].y == p[i].y)
			j++;
		for (int k = i; k <= j; k++) {
			if (!used[p[k].x]) {
				modify(p[k].x, 1);
				used[p[k].x] = true;
			}
		}
		vector <int> r;
		r.push_back(0);
		r.push_back(query(n) + 1);
		ans += 1ULL * query(n) * (query(n) + 1) / 2;
		for (int k = i; k <= j; k++) {
			r.push_back(query(p[k].x));
		}
		sort(r.begin(), r.end());
		for (int k = 1; k < (int) r.size(); k++) {
			int s = r[k] - r[k - 1];
			ans -= 1ULL * s * (s - 1) / 2;
		}
		i = j;
	}
	cout << ans << endl;
}