#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

const int N = 300;
int t, n, m, b[N], pos[N];
std::pair<int, int> a[N];

bool cmp(std::pair<int, int> a, std::pair<int, int> b) 
{
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

void add(int i) 
{
	while (i < m) {
		++b[i];
		i |= i + 1;
	}
}

int get(int i) 
{
	int s = 0;
	while (i >= 0) {
		s += b[i];
		i = (i & i + 1) - 1;
	}
	return s;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		memset(b, 0, m << 2);
		for (int i = 0; i < m; ++i) {
			scanf("%d", &a[i].first);
			a[i].second = i;
		}
		std::sort(a, a + m, cmp);
		int ans = 0;
		for (int i = 0; i < m; ++i) pos[a[i].second] = i;
		for (int i = 0; i < m; ++i) {
			ans += get(pos[i]);
			add(pos[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}