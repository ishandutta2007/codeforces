#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 2000010;
int n, m, val[maxn];
char str[maxn];
long long ans;
vector<int> tmp;
struct SAM {
	int cnt, root, last;
	int fa[maxn], ch[maxn][26], vis[maxn], r[maxn], b[maxn], t[maxn];
	inline int newstate() {
		++cnt;
		fa[cnt] = val[cnt] = 0;
		memset(ch[cnt], 0, sizeof(ch[cnt]));
		return cnt;
	}
	
	void init() {
		cnt = 0;
		root = last = newstate();
	}

	void extend(int w) {
		int p = last, np = newstate();
		val[np] = val[p] + 1;
		for (; p && !ch[p][w]; p = fa[p]) ch[p][w] = np;
		if (!p) fa[np] = root;
		else {
			int q = ch[p][w];
			if (val[p] + 1 == val[q]) fa[np] = q;
			else {
				int nq = newstate();
				memcpy(ch[nq], ch[q], sizeof ch[q]);
				val[nq] = val[p] + 1;
				fa[nq] = fa[q];
				fa[np] = fa[q] = nq;
				for (; p && ch[p][w] == q; p = fa[p]) ch[p][w] = nq;
			}
		}
		last = np;
	}

	void calcr() {
		for (int i = 0, p = root; i < n; ++i) {
			p = ch[p][str[i] - 'a'];
			++r[p];
		}
		
		for (int i = 1; i <= cnt; ++i) ++b[val[i]];
		for (int i = 1; i <= n; ++i) b[i] += b[i - 1];
		for (int i = 1; i <= cnt; ++i) t[b[val[i]]--] = i;
		for (int i = cnt; i >= 1; --i) {
			int now = t[i];
			r[fa[now]] += r[now];
		}
	}

	void work() {
		scanf("%s", str);
		m = strlen(str);
		for (int i = m; i < m * 2; ++i)
			str[i] = str[i - m];
		tmp.clear();
		ans = 0;
		for (int i = 0, p = root, len = 0; i < m * 2; ++i) {
			int t = str[i] - 'a';
			if (ch[p][t]) {
				p = ch[p][t]; ++len;
			}
			else {
				for (; p; p = fa[p]) 
					if (ch[p][t]) {
						len = val[p] + 1;
						p = ch[p][t];
						break;
					}
				if (!p) len = 0, p = root;
			}
			while (val[fa[p]] >= m) p = fa[p];
			if (len >= m && !vis[p]) {
 				vis[p] = 1; ans += r[p]; tmp.push_back(p);
			}
		}
		for (unsigned int i = 0; i < tmp.size(); ++i) vis[tmp[i]] = 0; 
		printf("%I64d\n", ans);	
	}
} sam;
int main() {
	scanf("%s", str);
	n = strlen(str);
	sam.init();
	for (int i = 0; i < n; ++i)
		sam.extend(str[i] - 'a');
	sam.calcr();
	int Q = 0; scanf("%d", &Q);
	for (int i = 1; i <= Q; ++i)
		sam.work();
}