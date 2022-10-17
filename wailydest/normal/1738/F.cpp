#include <cstdio>
#include <algorithm>

const int N = 1000;
int t, n, top[N];
bool u[N];
std::pair<int, int> a[N];

int find(int v) {
	if (top[v] == v) return v;
	return top[v] = find(top[v]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) top[b] = a;
}

int query(int v) {
	printf("? %d\n", v + 1);
	fflush(stdout);
	int re;
	scanf("%d", &re);
	return re - 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			top[i] = i;
			u[i] = 0;
			scanf("%d", &a[i].first);
			a[i].second = i;
		}
		std::sort(a, a + n);
		for (int i = n - 1; i >= 0; --i) {
			int id = a[i].second;
			if (!u[id]) {
				u[id] = 1;
				for (int j = 0; j < a[i].first; ++j) {
					int k = query(id);
					merge(k, id);
					if (u[k]) break;
					u[k] = 1;
				}
			}
		}
		printf("! ");
		for (int i = 0; i < n; ++i) printf("%d ", find(i) + 1);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}