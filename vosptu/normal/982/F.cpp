#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <ctime>
using namespace std;

#define N 210000

vector <int> ve[N], ve_rev[N], useful_edge[N];
bool used[N], okok[N];
int deg[N], st[N], cnt[N];
int len, n, m;

void doit(int x) {
	// printf("\n");
	memset(used, false, sizeof used);
	memset(deg, 0, sizeof deg);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < (int) ve[i].size(); j++) {
			int u = i, v = ve[i][j];
			if (u != x && v != x)
				deg[v] += 1;
		}
	// for (int i = 1; i <= n; i++)
	// 	printf("?? %d\n", deg[i]);
	int len = 0;
	for (int i = 1; i <= n; i++)
		if (i != x && deg[i] == 0) {
			st[++len] = i;
		}
	for (int i = 1; i <= len; i++) {
		used[st[i]] = true;
		// printf("qq %d\n", st[i]);
		for (int j = 0; j < (int) ve[st[i]].size(); j++) {
			// printf("edge %d %d\n", s);
			if (ve[st[i]][j] != x) {
				// printf("-- %d\n", ve[st[i]][j]);
				--deg[ve[st[i]][j]];
				if (deg[ve[st[i]][j]] == 0) {
					// printf("?? %d\n", deg[ve[st[i]][j]]);
					st[++len] = ve[st[i]][j];
				}
			}
		}
	}
	// for (int i = 1; i <= n; i++)
	// 	printf("?? %d\n", deg[i]);
	// printf("!! %d\n", len);
	if (len == n - 1) {
		printf("%d\n", x);
		exit(0);
	}

	memset(deg, 0, sizeof deg);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < (int) ve_rev[i].size(); j++) {
			int u = i, v = ve_rev[i][j];
			if (u != x && v != x)
				deg[v] += 1;
		}
	len = 0;
	for (int i = 1; i <= n; i++)
		if (i != x && deg[i] == 0) {
			st[++len] = i;
		}
	for (int i = 1; i <= len; i++) {
		used[st[i]] = true;
		for (int j = 0; j < (int) ve_rev[st[i]].size(); j++)
			if (ve_rev[st[i]][j] != x && (--deg[ve_rev[st[i]][j]]) == 0) {
				st[++len] = ve_rev[st[i]][j];
			}
	}
	if (len == n - 1) {
		printf("%d\n", x);
		exit(0);
	}

	for (int i = 1; i <= n; i++)
		if (!used[i] && i != x) {
			cnt[i] += 1;
		}

}

int main() {
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		// if (i == m)
		// 	x = 2, y = 1;
		// else if (i == m - 1)
		// 	x = n, y = 1;
		// else
		// 	x = i, y = i + 1;
		scanf("%d%d", &x, &y);
		// x = rand() % n + 1, y = rand() % n + 1;
		ve[x].push_back(y);
		ve_rev[y].push_back(x);
		// printf("inp %d %d\n", x, y);
	}

	memset(deg, 0, sizeof deg);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < (int) ve_rev[i].size(); j++) {
			int v = ve_rev[i][j];
			deg[v] += 1;
		}
	len = 0;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0) {
			st[++len] = i;
		}
	for (int i = 1; i <= len; i++) {
		used[st[i]] = true;
		for (int j = 0; j < (int) ve_rev[st[i]].size(); j++)
			if ((--deg[ve_rev[st[i]][j]]) == 0) {
				st[++len] = ve_rev[st[i]][j];
			}
	}
	for (int i = 1; i <= n; i++)
		if (used[i])
			okok[i] = false;
		else
			okok[i] = true;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < (int) ve[i].size(); j++)
			if (okok[ve[i][j]])
				useful_edge[i].push_back(ve[i][j]);
	// for (int i = 1; i <= 50; i++) {
	// 	int k = rand() % n + 1;
	// 	memset(used, false, sizeof used);
	// 	len = 0;
	// 	while (!used[k]) {
	// 		st[++len] = k;
	// 		used[k] = true;
	// 		k = ve[k][rand() % ve[k].size()];
	// 	}
	// 	for (int j = len; ; j--) {
	// 		cnt[st[j]] += 1;
	// 		if (st[j] == k)
	// 			break;
	// 	}
	// }

	for (int T = 0; ; T++) {
		vector <int> V;
		for (int i = 1; i <= n; i++)
			if (cnt[i] == 0 + 2 * T)
				V.push_back(i);
		if (V.size() == 0)
			break;

		int v = V[rand() % V.size()];
		doit(v);
		// printf("%d\n", v);

		V.clear();
		for (int i = 1; i <= n; i++)
			if (cnt[i] == 1 + 2 * T)
				V.push_back(i);

		// printf("%d %d\n", cnt[1], cnt[2]);
		if (V.size() == 0)
			break;
		v = V[rand() % V.size()];
		memset(used, false, sizeof used);
		len = 0;
		// bool fi = true;
		while (!used[v]) {
			st[++len] = v;
			used[v] = true;
			// if (useful_edge[v].size() == 0)
			// 	fi = false;
			v = useful_edge[v][rand() % useful_edge[v].size()];
		}
		// if (!fi) {
		// 	for (int j = 1; j <= n; j++)
		// 		cnt[j] += 1;
		// }else
		for (int j = len; j > 0; j--) {
			cnt[st[j]] += 1;
			if (st[j] == v)
				break;
		}
		// if (clock() / CLOCKS_PER_SEC > 0.5)
		// 	break;
		// printf("??%ld\n", );
	}

	printf("-1\n");


}