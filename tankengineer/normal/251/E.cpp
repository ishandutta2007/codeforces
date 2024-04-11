#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005 << 1, MOD = 1000000007;
int n, size[N], dep[N], grandSon[N];
vector<int> edge[N], ch[N];
int mem[N];

void DFS(int i, int fa) {
	size[i] = 1;
	grandSon[i] = -1;
	for (int j = 0; j < (int)edge[i].size(); ++j) {
		int v = edge[i][j];
		if (v == fa) {
			continue;
		}
		ch[i].push_back(v);
		dep[v] = dep[i] + 1;
		DFS(v, i);
		size[i] += size[v];
		if (ch[v].size() == 2) {
			grandSon[i] = v;
		} else if (grandSon[v] != -1 && (grandSon[i] == -1 || dep[grandSon[v]] < dep[grandSon[i]])) {
			grandSon[i] = grandSon[v];
		}
	}
}

int type2(int, int);

int type1(int v) {
	if (mem[v] != -1) {
		return mem[v];
	}
	if (ch[v].size() == 1) {
		if (grandSon[v] == -1) {
			return mem[v] = size[v] / 2;
		} else {
			int w = grandSon[v];
			long long ret = 0;
			if (dep[w] > dep[v] + 1) {
				ret = type1(ch[ch[v][0]][0]);
			}
			int d1 = ch[w][0], d2 = ch[w][1];
			int space = dep[w] - dep[v] - 1;
			if (size[d1] == space && ch[d1].size() <= 1 && grandSon[d1] == -1) {
				(ret += type1(d2)) %= MOD;
			}
			if (size[d2] == space && ch[d2].size() <= 1 && grandSon[d2] == -1) {
				(ret += type1(d1)) %= MOD;
			}
			space = dep[w] - dep[v] + 1;
			if (ch[d1].size() == 1) {
				if (size[d1] == space && ch[d1].size() <= 1 && grandSon[d1] == -1) {
					(ret += type1(d2)) %= MOD;
				}
			} else if (ch[d1].size() == 2) {
				int t1 = ch[d1][0], t2 = ch[d1][1];
				if (size[t1] == space - 1 && ch[t1].size() <= 1 && grandSon[t1] == -1) {
					(ret += type2(d2, t2)) %= MOD;
				}
				if (size[t2] == space - 1 && ch[t2].size() <= 1 && grandSon[t2] == -1) {
					(ret += type2(d2, t1)) %= MOD;
				}
			}
			if (ch[d2].size() == 1) {
				if (size[d2] == space && ch[d2].size() <= 1 && grandSon[d2] == -1) {
					(ret += type1(d1)) %= MOD;
				}
			} else if (ch[d2].size() == 2) {
				int t1 = ch[d2][0], t2 = ch[d2][1];
				if (size[t1] == space - 1 && ch[t1].size() <= 1 && grandSon[t1] == -1) {
					(ret += type2(d1, t2)) %= MOD;
				}
				if (size[t2] == space - 1 && ch[t2].size() <= 1 && grandSon[t2] == -1) {
					(ret += type2(d1, t1)) %= MOD;
				}
			}
			return mem[v] = ret;
		}
	} else {
		int d1 = ch[v][0], d2 = ch[v][1];
		long long ret = 0;
		if (ch[d1].size() == 0) {
			ret += type1(d2);
		} else if (ch[d1].size() == 1) {
			ret += type2(d2, ch[d1][0]);
		}
		if (ch[d2].size() == 0) {
			ret += type1(d1);
		} else if (ch[d2].size() == 1) {
			ret += type2(d1, ch[d2][0]);
		}
		ret %= MOD;
		return mem[v] = ret;
	}
}

int type2(int v1, int v2) {
	if (ch[v1].size() == 2 || ch[v2].size() == 2) {
		return 0;
	}
	if (ch[v1].size() == 0 && ch[v2].size() == 0) {
		return 1;
	}
	if (ch[v1].size() == 1 && ch[v2].size() == 1) {
		return type2(ch[v1][0], ch[v2][0]);
	}
	if (ch[v1].size() == 1 && ch[v2].size() == 0) {
		return type1(ch[v1][0]);
	} else {
		return type1(ch[v2][0]);
	}
}

int main() {
	memset(mem, -1, sizeof(mem));
	scanf("%d", &n);
	if (n == 1) {
		printf("2\n");
		return 0;
	}
	n *= 2;
	for (int i = 0; i < n - 1; ++i) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		--t1; --t2;
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
	}
	int root = 0;
	for (int i = 0; i < n; ++i) {
		if (edge[i].size() > edge[root].size()) {
			root = i;
		}
	}
	if (edge[root].size() > 3) {
		printf("0\n");
		return 0;
	}
	if (edge[root].size() == 2) {
		n /= 2;
		int ans = ((long long)2 * n * n - 2 * n + 4) % MOD;
		printf("%d\n", ans);
		return 0;
	}
	DFS(root, -1);
	long long ans = 0;
	vector<int> ord;
	for (int i = 0; i < 3; ++i) {
		ord.push_back(i);
	}
	do {
		vector<int> son;
		for (int i = 0; i < 3; ++i) {
			son.push_back(ch[root][ord[i]]);
		}
		if (ch[son[2]].size() == 0) {
			if (size[son[0]] & 1) {
				ans += 0;
			} else {
				(ans += (long long)type1(son[0]) * type1(son[1]) % MOD) %= MOD;
			}
		} else if (ch[son[2]].size() == 1) {
			int d = ch[son[2]][0];
			if ((size[son[0]] + size[d]) & 1) {
				ans += 0;
			} else {
				(ans += (long long)type2(son[0], d) * type1(son[1]) % MOD) %= MOD;
			}
			if ((size[son[1]] + size[d]) & 1) {
				ans += 0;
			} else {
				(ans += (long long)type1(son[0]) * type2(son[1], d) % MOD) %= MOD;
			}
		} else if (ch[son[2]].size() == 2) {
			int d1 = ch[son[2]][0], d2 = ch[son[2]][1];
			if ((size[son[0]] + size[d1]) & 1) {
				ans += 0;
			} else {
				(ans += (long long)type2(son[0], d1) * type2(son[1], d2) % MOD) %= MOD;
			}
			if ((size[son[0]] + size[d2]) & 1) {
				ans += 0;
			} else {
				(ans += (long long)type2(son[0], d2) * type2(son[1], d1) % MOD) %= MOD;
			}
		}
	} while (next_permutation(ord.begin(), ord.end()));
	(ans *= 2) %= MOD;
	printf("%d\n", (int)ans);
	return 0;
}