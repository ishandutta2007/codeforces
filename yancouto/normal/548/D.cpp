#include <cstdio>
#ifndef ONLINE_JUDGE
#define debug(...) {fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, __VA_ARGS__);}
#else
#define debug(...) //
#endif
#include <algorithm>
using namespace std;

int n;
int a[200003];
pair<int, int> p[200003];

bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
	return p1.first > p2.first;
}

int s[200003];
bool active[200003];
int size[200003];
int mx[200003];

int find(int i) {
	if(s[s[i]] != s[i]) s[i] = find(s[i]);
	return s[i];
}
int max_size = 1;
int maxes[200003];

void join(int i, int j) {
	i = find(i); j = find(j);
	if(size[i] < size[j]) swap(i, j);
	size[i] += size[j];
	s[j] = i;
	mx[i] = min(mx[i], mx[j]);
//	debug("new mx[%d] = %d\n", i + 1, mx[i]);

	for(int k = max_size + 1; k <= size[i]; k++) {
		maxes[k] = mx[i];
//		debug("maxes[%d] = %d\n", k, mx[i]);
	}
	max_size = max(max_size, size[i]);
}

int main() {
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		p[i].first = a[i];
		p[i].second = i;
		s[i] = i;
		size[i] = 1;
		active[i] = false;
		maxes[1] = max(maxes[1], a[i]);
		mx[i] = a[i];
	}
	sort(p, p + n, comp);
	for(i = 0; i < n; i++) {
		int p_i = p[i].second;
		active[p_i] = true;
		if(p_i + 1 < n && active[p_i + 1]) {
//			debug("joing %d[%d] with %d[%d]\n", p_i + 1, a[p_i], p_i + 2, a[p_i + 1]);
			join(p_i, p_i + 1);
		}
		if(p_i > 0 && active[p_i - 1]) {
//			debug("joing %d[%d] with %d[%d]\n", p_i + 1, a[p_i], p_i, a[p_i - 1]);
			join(p_i - 1, p_i);
		}
	}
	for(i = 1; i <= n; i++)
		printf("%d ", maxes[i]);
	putchar('\n');

}