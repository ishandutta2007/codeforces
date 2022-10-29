#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector> 
using namespace std;
const int maxn = 200010;
int n, root, ans, a[maxn], s[maxn], circle[maxn], visit[maxn];
void check(int st) {
	int x = st, m = 0;
	while (!visit[x]) {
		visit[x] = st;
		s[++m] = x;
		x = a[x];
	}
	if (x != a[x] && visit[x] == st) {
		circle[++ans] = s[m];
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		if (a[i] == i) root = i;
	}
	for (int i = 1; i <= n; ++i)
		if (!visit[i]) check(i);
	if (!root) root = circle[1];
	for (int i = 1; i <= ans; ++i)
		a[circle[i]] = root;
	
	for (int i = 1; i <= n; ++i)
		if (a[i] == i && i != root) {
			a[i] = root;
			++ans;
		}
	printf("%d\n", ans);
	for (int i = 1; i < n; ++i)
		printf("%d ", a[i]);
	printf("%d\n", a[n]);
}