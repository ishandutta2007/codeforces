#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 8005;

int n, l[N], r[N], f[N], g[N], evt[N], tim[N], pre[N], top, ord[N];
vector<int> ans[N], rec[N];
bool vis[N];

void dp(const int i) {
	if (vis[i]) return;
  vis[i] = true;
  for (int j = l[i]; j <= r[i]; ++j) {
	  rec[j].clear();
	  f[j] = 0;
	}
	for (int j = 1; j <= n; ++j) {
	  if (j == i) continue;
	  if (l[j] >= l[i] && r[j] <= r[i]) dp(j);
	}
	for (int j = 1; j <= n; ++j) {
	  if (j == i) continue;
	  if (l[j] >= l[i] && r[j] <= r[i]) rec[r[j]].push_back(j);
	}
	for (int j = l[i] + 1; j <= r[i]; ++j) {
	  f[j] = f[j - 1];
	  pre[j] = -1;
	  for (int k = 0; k < rec[j].size(); ++k) {
		  if (f[l[rec[j][k]]] + g[rec[j][k]] + 1 > f[j]) {
			  f[j] = f[l[rec[j][k]]] + g[rec[j][k]] + 1;
			  pre[j] = rec[j][k];
			}
		}
	}
	g[i] = f[r[i]];
	int t1 = r[i];
	while (t1 != l[i]) {
	  if (pre[t1] == -1) {
		  --t1;
		} else {
		  for (int j = 0; j < ans[pre[t1]].size(); ++j) ans[i].push_back(ans[pre[t1]][j]);
			ans[i].push_back(pre[t1]);
			t1 = l[pre[t1]];
		}
	}
}

bool cmp(const int i, const int j) {return tim[i] < tim[j];}

void mark(const int pos, const int val) {
  if (pos > 0) l[pos] = val; else r[-pos] = val;
}

int look(const int pos) {
  return pos > 0 ? l[pos] : r[-pos];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
	  scanf("%d %d", &l[i], &r[i]);
	  l[i] -= r[i];
	  r[i] = r[i] * 2 + l[i];
	  evt[++top] = i; tim[top] = l[i]; ord[top] = top;
	  evt[++top] = -i; tim[top] = r[i]; ord[top] = top;
	}
	++n; l[n] = -2000000009; r[n] = 2000000009;
	evt[++top] = n; tim[top] = l[n]; ord[top] = top;
	evt[++top] = -n; tim[top] = r[n]; ord[top] = top;
	sort(ord + 1, ord + 1 + top, cmp);
	mark(evt[ord[1]], 1);
	for (int i = 2; i <= top; ++i) mark(evt[ord[i]], look(evt[ord[i - 1]]) + (tim[ord[i]] != tim[ord[i - 1]]));
	for (int i = 1; i <= n; ++i) dp(i);
	/*
	for (int i = 1; i <= n; ++i) {
	  printf("Info %d:\n", i);
	  printf("L %d R %d\n", l[i], r[i]);
	  printf("Best %d\n", g[i]);
	  for (int j = 0; j < g[i]; ++j) printf("%d ", ans[i][j]);
		printf("\n\n");
	}
	*/
	printf("%d\n", g[n]);
	sort(ans[n].begin(), ans[n].end());
	for (int i = 0; i < g[n]; ++i) printf("%d ", ans[n][i]);
	return 0;
}