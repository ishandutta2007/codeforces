#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 100005, M = 100005;

int n, m, t1, t2, top, v[M], next[M], head[N], d[N];
bool vis[N];

int abss(const int i) {return i < 0 ? -i : i;}

int gcd(const int x, const int y) {
  if (x == 0 || y == 0) return x + y;
  int a = x, b = y, c = a % b;
  while (c) {
	  a = b;
	  b = c;
	  c = a % b;
	}
	return b;
}

void dfs(const int i) {
  vis[i] = true;
  for (int j = head[i]; j; j = next[j]) {
	  if (!vis[v[j]]) {
		  d[v[j]] = d[i] + 1;
		  dfs(v[j]);
		}
	}
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
		scanf("%d %d", &t1, &t2);
		++top; v[top] = t2; next[top] = head[t1]; head[t1] = top;
	}
	dfs(1);
	int tmp = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) continue;
		//printf("D%d %d\n", i, d[i]);
		for (int j = head[i]; j; j = next[j]) {
		  tmp = gcd(tmp, abss(d[v[j]] - d[i] - 1));
		}
	}
	if (tmp == 0) tmp = n;
	printf("%d\n", tmp);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) if (vis[i] && d[i] % tmp == 0) ++cnt;
	printf("%d\n", cnt);
	for (int i = 1; i <= n; ++i) if (vis[i] && d[i] % tmp == 0) printf("%d ", i);
	return 0;
}