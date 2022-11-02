#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

const int N = 100005, M = 100005;

int n, m;

int u[M], v[M], ans[M];

char c[N];

vector<pair<int, int> > edge[N];

int col3[N], sum[N];

void construct_single(int u, int fa = -1) {
	sum[u] = 0;
	for (int i = 0; i < (int)edge[u].size(); ++i) {
		int v = edge[u][i].first, id = edge[u][i].second;
		if (v == fa) {
			continue;
		}
		if (sum[v] == -1) {
			construct_single(v, u);
			int delta = col3[v] - sum[v] % 3;
			if (delta <= 0) {
				delta += 3;
			}
			sum[u] += delta;
			sum[v] += delta;
			ans[id] = delta;
			assert(sum[v] % 3 == col3[v]);
		} else {
			sum[u] += 3;
			ans[id] = 3;
		}
	}
}

vector<int> cycle, stack;

bool instack[N];

int col2[N], fae[N];

bool bipartite_test(int u, int fa = -1) {
	col2[u] = fa == -1 ? 0 : 1 - col2[fa];
	instack[u] = true;
	stack.push_back(u);
	for (int i = 0; i < (int)edge[u].size(); ++i) {
		int v = edge[u][i].first;
		if (v == fa) {
			continue;
		}
		if (col2[v] == -1) {
			fae[v] = edge[u][i].second;
			if (!bipartite_test(v, u)) {
				return false;
			}
		} else if (col2[v] == col2[u]) {
			while (stack.back() != v) {
				cycle.push_back(stack.back());
				stack.pop_back();
			}
			cycle.push_back(v);
			stack.pop_back();
			fae[v] = edge[u][i].second;
			return false;
		}
	}
	instack[u] = false;
	stack.pop_back();
	return true;
}

void fix_construct_bipartite(int u, int fa = -1) {
	sum[u] = 0;
	for (int i = 0; i < (int)edge[u].size(); ++i) {
		int v = edge[u][i].first, id = edge[u][i].second;
		if (v == fa) {
			continue;
		}
		if (sum[v] == -1) {
			fae[v] = id;
			fix_construct_bipartite(v, u);
			int delta = col2[v] - sum[v] % 3;
			if (delta <= 0) {
				delta += 3;
			}
			sum[u] += delta;
			sum[v] += delta;
			ans[id] = delta;
			assert(sum[v] % 3 == col2[v]);
		} else {
			sum[u] += 3;
			ans[id] = 3;
		}
	}
}

void construct_bipartite() {
	fix_construct_bipartite(0);
	if (sum[0] % 3 == 1) {
		for (int i = 1; i < n; ++i) {
			if (col2[i] == 0) {
				int u = i;
				while (u != 0) {
					int ue = fae[u], fa = ::u[ue] + v[ue] - u, old = ans[ue];
					ans[ue] += 2;
					if (ans[ue] > 3) {
						ans[ue] -= 3;
					}
					int deltae = ans[ue] - old;
					sum[u] += deltae;
					sum[fa] += deltae;
					
					int ve = fae[fa], ffa = ::u[ve] + v[ve] - fa;
					old = ans[ve];
					ans[ve] -= 2;
					if (ans[ve] <= 0) {
						ans[ve] += 3;
					}
					deltae = ans[ve] - old;
					sum[fa] += deltae;
					sum[ffa] += deltae;

					u = ffa;
				}
				break;
			}
		}
	}
}

void construct_non_bipartite() {
	int root = cycle[0];
	construct_single(root);
	int delta = col3[root] - sum[root] % 3;
	if (delta < 0) {
		delta += 3;
	}
	delta = 3 - delta;
	for (int i = 0; i < (int)cycle.size(); ++i) {
		int u = cycle[i], ue = fae[u], old = ans[ue];
		if (i & 1) {
			ans[ue] += 3 - delta;
		} else {
			ans[ue] += delta;
		}
		ans[ue] %= 3;
		if (ans[ue] == 0) {
			ans[ue] = 3;
		}
		int deltae = ans[ue] - old;
		sum[::u[ue]] += deltae;
		sum[v[ue]] += deltae;
	}
}

int nsum[N];

bool selfcheck() {
	bool ret = true;
	for (int i = 0; i < m; ++i) {
		if (ans[i] <= 0 || ans[i] > 3) {
			printf("Edge %i has invalid weight!\n", i);
			ret = false;
		}
		nsum[u[i]] += ans[i];
		nsum[v[i]] += ans[i];
	}
	for (int i = 0; i < n; ++i) {
		if (sum[i] != nsum[i]) {
			printf("Node %d has invalid sum!\n", i);
			ret = false;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (sum[u[i]] == sum[v[i]]) {
			printf("Node %d and node %d connected by edge %d have the same sum!\n", u[i], v[i], i);
			ret = false;
		}
	}
	return ret;
}

int main() {
	scanf("%d%d%s", &n, &m, c);
	for (int i = 0; i < n; ++i) {
		col3[i] = 'Z' - c[i];
		col2[i] = -1;
		sum[i] = -1;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", u + i, v + i);
		edge[u[i]].push_back(make_pair(v[i], i));
		edge[v[i]].push_back(make_pair(u[i], i));
	}
	int root = -1;
	for (int i = 0; i < n && root == -1; ++i) {
		if (edge[i].size() == 1) {
			root = i;
		}
	}
	if (root != -1) {
		construct_single(root);
	} else {
		if (bipartite_test(0)) {
			construct_bipartite();
		} else {
			construct_non_bipartite();
		}
	}
	for (int i = 0; i < m; ++i) {
		printf("%d %d %d\n", u[i], v[i], ans[i]);
	}
	assert(selfcheck());
	return 0;
}