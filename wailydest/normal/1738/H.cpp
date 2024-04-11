#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int A = 26;
const int N = 1000005;
const int Q = N * 2;
int q, res1[N], res2[Q], last, len[N], clen, size, to[N][A], in[N], out[N], t[N * 2], end[Q], link[N];
char str[N], c1[N], c2[Q];
std::vector<int> g[N];
bool type1[N], type2[Q];

void add_c(int c) {
	str[clen] = c;
	while (str[clen - 1 - len[last]] != c) last = link[last];
	if (to[last][c] < 2) {
		len[size] = len[last] + 2;
		int pre = last;
		do {
			pre = link[pre];
		} while (str[clen - 1 - len[pre]] != c);
		link[size] = to[pre][c];
		to[last][c] = size;
		++size;
	}
	last = to[last][c];
	++clen;
}

int dt;
void dfs(int v) {
	in[v] = dt++;
	for (int i = 0; i < (int)g[v].size(); ++i) dfs(g[v][i]);
	out[v] = dt;
}

void set(int i, int x) {
	for (i += size, t[i] = x; i > 1; i >>= 1) t[i >> 1] = std::max(t[i], t[i ^ 1]);
}

int query(int l, int r) {
	int ans = 0;
	for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ans = std::max(ans, t[l++]);
		if (r & 1) ans = std::max(ans, t[--r]);
	}
	return ans;
}

void calc(bool *type, char *c, int q, int *res) {
	memset(to, 0, sizeof to);
	size = 2;
	len[0] = -1;
	len[1] = 0;
	link[1] = 0;
	clen = 1;
	last = 0;
	for (int i = 0; i < A; ++i) to[0][i] = 1;
	str[0] = -1;
	for (int i = 0; i < q; ++i) {
		if (type[i]) add_c(c[i] - 'a');
		end[i] = last;
	}
	for (int i = 0; i < size; ++i) g[i].clear();
	for (int i = 1; i < size; ++i) g[link[i]].push_back(i);
	dt = 0;
	dfs(0);
	int fi = 0, la = 0;
	memset(t, 0, sizeof t);
	int v = 0;
	for (int i = 0; i < q; ++i) {
		if (type[i]) {
			++la;
			while (str[la - len[v] - 1] != str[la]) v = link[v];
			v = to[v][str[la]];
			while (len[v] > la - fi) v = link[v];
			if (len[v] && query(in[v], out[v]) - len[v] < fi) res[i] = 1;
			set(in[v], la);
		} else ++fi;
	}
}

int main() {
	scanf("%d", &q);
	int fi = 0, la = 0;
	for (int i = 0; i < q; ++i) {
		char s[5];
		scanf("%s", s);
		if (s[1] == 'u') {
			type1[i] = 1;
			scanf(" %c", c1 + i);
			str[la++] = c1[i];
		} else {
			type2[i] = 1;
			c2[i] = str[fi];
			++fi;
		}
	}
	int qcnt = la - fi + q;
	for (int i = 0; fi < la; ++i, ++fi) {
		type2[q + i] = 1;
		c2[q + i] = str[fi];
	}
	calc(type1, c1, q, res1);
	std::reverse(c2, c2 + qcnt);
	std::reverse(type2, type2 + qcnt);
	calc(type2, c2, qcnt, res2);
	int ans = 0;
	for (int i = 0; i < q; ++i) {
		ans += res1[i] - res2[qcnt - 1 - i];
		printf("%d\n", ans);
	}
	return 0;
}