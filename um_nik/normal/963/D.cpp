#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int L = 100100;
const int N = (int)5e5;
const int A = 26;

struct Node {
	int go[A];
	int len;
	int suffLink;

	Node() {
		for (int i = 0; i < A; i++)
			go[i] = -1;
		len = 0;
		suffLink = -1;
	}
};

struct Query {
	int v, k, id;

	Query() : v(), k(), id() {}
	Query(int _v, int _k, int _id) : v(_v), k(_k), id(_id) {}
};

Node SA[N];
int m;
char p[L];
char s[L];
int ans[L];
vector<Query> Q[L];
vector<int> a[N];
int q;

int build(int v, int c) {
	int nv = m++;
	SA[nv].len = SA[v].len + 1;
	SA[nv].suffLink = 0;
	while(v != -1 && SA[v].go[c] == -1) {
		SA[v].go[c] = nv;
		v = SA[v].suffLink;
	}
	if (v == -1) return nv;
	int u = SA[v].go[c];
	if (SA[v].len + 1 == SA[u].len) {
		SA[nv].suffLink = u;
		return nv;
	}
	int nu = m++;
	SA[nu] = SA[u];
	SA[nu].len = SA[v].len + 1;
	SA[u].suffLink = SA[nv].suffLink = nu;
	while(v != -1 && SA[v].go[c] == u) {
		SA[v].go[c] = nu;
		v = SA[v].suffLink;
	}
	return nv;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	m = 1;
	scanf("%s", s);
	int l = strlen(s);
	int len = l;
	for (int i = 0; i < len; i++)
		p[i] = s[i];
	int v = 0;
	for (int i = 0; i < l; i++) {
		int c = (int)(s[i] - 'a');
		v = build(v, c);
	}
	scanf("%d", &q);
	for (int id = 0; id < q; id++) {
		ans[id] = -1;
		int k;
		scanf("%d %s", &k, s);
		l = strlen(s);
		v = 0;
		for (int i = 0; i < l && v != -1; i++) {
			int c = (int)(s[i] - 'a');
			v = SA[v].go[c];
		}
		if (v == -1) continue;
		Q[l].push_back(Query(v, k, id));
	}
	for (int i = 0; i < len; i++)
		s[i] = p[i];
	for (l = 1; l < L; l++) {
		if (Q[l].empty()) continue;
		for (int i = 0; i < m; i++)
			a[i].clear();
		v = 0;
		for (int i = 0; i < len; i++) {
			int c = (int)(s[i] - 'a');
			while(SA[v].go[c] == -1)
				v = SA[v].suffLink;
			v = SA[v].go[c];
			while(SA[SA[v].suffLink].len >= l)
				v = SA[v].suffLink;
			if (SA[v].len >= l)
				a[v].push_back(i);
		}
		for (Query qq : Q[l]) {
			v = qq.v;
			if ((int)a[v].size() < qq.k) continue;
			int id = qq.id;
			ans[id] = len;
			for (int i = qq.k - 1; i < (int)a[v].size(); i++)
				ans[id] = min(ans[id], a[v][i] - a[v][i - qq.k + 1]);
			ans[id] += l;
		}
	}
	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);

	return 0;
}