#include<cassert>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000005;

int ord[N], rnk[N], cnt[N], tmp[N], tmp2[N];

void suffixArray(char *s, int n, int m) {
	memset(cnt, 0, sizeof(int) * m);
	for (int i = 0; i < n; ++i) {
		++cnt[s[i] == ')'];
	}
	for (int i = 0; i + 1 < m; ++i) {
		cnt[i + 1] += cnt[i];
	}
	for (int i = 0; i < n; ++i) {
		rnk[--cnt[s[i] == ')']] = i;
	}
	ord[rnk[0]] = 0;
	for (int i = 1; i < n; ++i) {
		int u = rnk[i], v = rnk[i - 1];
		ord[u] = ord[v] + (s[u] != s[v]);
	}
	m = ord[rnk[n - 1]] + 1;
	for (int d = 1; d < n && m < n; d <<= 1) {
		memset(cnt, 0, sizeof(int) * m);
		for (int i = 0; i < n; ++i) {
			++cnt[ord[i]];
		}
		for (int i = 0; i + 1 < m; ++i) {
			cnt[i + 1] += cnt[i];
		}
		for (int i = 0; i < n; ++i) {
			int p = rnk[i] >= d ? rnk[i] - d : n + rnk[i] - d;
			tmp[i] = p;
			tmp2[p] = ord[rnk[i]];
		}
		for (int i = n - 1; i >= 0; --i) {
			rnk[--cnt[ord[tmp[i]]]] = tmp[i];
		}
		memcpy(tmp, ord, sizeof(int) * n);
		ord[rnk[0]] = 0;
		for (int i = 1; i < n; ++i) {
			int u = rnk[i], v = rnk[i - 1];
			ord[u] = ord[v] + (tmp[u] != tmp[v] || tmp2[u] != tmp2[v]);
		}
		m = ord[rnk[n - 1]] + 1;
	}
}

int n;

char s[N];

void sortSuf() {
	suffixArray(s, n, 2);
}

bool use[N];

void mark(int bar) {
	deque<pair<int, int> > q;
	int tag = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			++cnt;
		} else {
			--cnt;
		}
		while (q.size() && q.back().second >= cnt) {
			q.pop_back();
		}
		q.push_back(make_pair(i, cnt));
	}
	for (int i = 0; i < n; ++i) {
		while (q.size() && q.front().first < i) {
			q.pop_front();
		}
		if (q.front().second + tag >= bar) {
			use[i] = true;
		}
		if (s[i] == '(') {
			--tag;
		} else {
			++tag;
		}
		while (q.size() && q.back().second >= cnt - tag) {
			q.pop_back();
		}
		q.push_back(make_pair(i + n, cnt - tag));
	}
}

char ans[N << 1];

int main() {
	scanf("%s", s);
	n = strlen(s);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			++cnt;
		} else {
			--cnt;
		}
	}
	mark(min(0, cnt));
	sortSuf();
	for (int i = 0; i < n; ++i) {
		int u = rnk[i];
		if (use[u]) {
			int top = 0;
			while (cnt < 0) {
				ans[top++] = '(';
				++cnt;
			}
			for (int j = 0; j < n; ++j) {
				ans[top++] = s[(u + j) % n];
			}
			while (cnt > 0) {
				ans[top++] = ')';
				--cnt;
			}
			ans[top++] = '\0';
			puts(ans);
			break;
		}
	}
	return 0;
}