#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define F first
#define S second

const int maxn = 200005;
int a[maxn], b[maxn];
bool vis[maxn];
set<pii> S;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		b[i] += a[i];
		S.insert(pii(b[i], i));
	}
	bool flag = true;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		auto it = S.begin();
		int x = it->F;
		int id = it->S;
		S.erase(it);
		if (a[id] > x) {
			flag = false;
			break;
		}
		ans += x - a[id];
		a[id] = x;
		vis[id] = true;
		if (id - 1 >= 1 && !vis[id - 1]) {
			S.erase(pii(b[id - 1], id - 1));
			b[id - 1] = min(b[id - 1], x + 1);
			S.insert(pii(b[id - 1], id - 1));
		}
		if (id + 1 <= n && !vis[id + 1]) {
			S.erase(pii(b[id + 1], id + 1));
			b[id + 1] = min(b[id + 1], x + 1);
			S.insert(pii(b[id + 1], id + 1));
		}
	}
	if (!flag) puts("-1");
	else {
		printf("%I64d\n", ans);
		for (int i = 1; i <= n; ++i) {
			printf("%d", a[i]);
			if (i == n) puts("");
			else printf(" ");
		}
	}
	return 0;
}