#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 3005;
int n, m, pre[maxn * 2], l[maxn][maxn], r[maxn][maxn];
char s[maxn][maxn];
long long ans;
struct Tree {
	int v[maxn];
	void add(int x, int delta) {
		x = n - x + 1;
		while (x <= n) {
			v[x] += delta; x += x & (-x);
		}
	}
	int query(int x) {
		x = n - x + 1;
		int ret = 0;
		while (x) {
			ret += v[x]; x -= x & (-x);
		}
		return ret;
	}
} T[maxn * 2];
vector<int> E[maxn][maxn];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			if (s[i][j] == 'z') l[i][j] = l[i][j - 1] + 1;
			else l[i][j] = 0;
		for (int j = m; j >= 1; --j)
			if (s[i][j] == 'z') r[i][j] = r[i][j + 1] + 1;
			else r[i][j] = 0;
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			int index = i + j;
			if (s[i][j] == 'z') {
				if (i + l[i][j] <= n && j - l[i][j]) 
					E[i + l[i][j]][j - l[i][j]].push_back(i);
				T[index].add(i, 1);
				for (unsigned int k = 0; k < E[i][j].size(); ++k) {
					int t = E[i][j][k];
					if (t > pre[index]) T[index].add(t, -1);
				}
				
				int p = max(1, i - r[i][j] + 1);
				ans += T[index].query(p);
			}
			else {
				for (int x = i - 1, y = j + 1; x > pre[index] && y <= m; --x, ++y)
					if (x + l[x][y] >= i) T[index].add(x, -1);
				pre[index] = i;
			}
		}
	printf("%I64d\n", ans);
}