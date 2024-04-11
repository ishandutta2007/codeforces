#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k, p;

const int N = 100005;
vector<int> edge[N];

int dep[N], cnt[N];

void go(int u, int fa) {
	++cnt[dep[u]];
	for (int j = 0; j < (int)edge[u].size(); ++j) {
		int v = edge[u][j];
		if (v != fa) {
			dep[v] = dep[u] + 1;
			go(v, u);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edge[u].push_back(v), edge[v].push_back(u);
	}
	go(0, -1);
	cnt[0] = 0;
	int m = 0;
	for (int i = 0; i < n; ++i) {
		m = max(m, dep[i]);
	}
	int l = 1, r = 1, size = 0;
	long long sum = 0;
	int ans = 0;
	for (int r = 1; r <= m; ++r) {
		sum += size;	
		while (sum > p) {
			sum -= (long long)cnt[l] * (r - l);
			size -= cnt[l];
			++l;		
		}
		size += cnt[r];
		int resize = size;
		resize += min((p - sum) / (r - l + 1), (long long)cnt[l - 1]);
		ans = max(ans, min(resize, k));
	}
	printf("%d\n", ans);
	return 0;
}