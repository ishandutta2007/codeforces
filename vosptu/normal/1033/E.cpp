#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
using namespace std;

vector <int> S1, S2;
int e[700][700];
int a[700], len;
int newedgel;
int n;
bool used[700];

int E[700][700];

int cost = 0;
int query(vector <int> S) {
	cost ++;
	// int ans = 0;
	// for (int i = 0; i < (int) S.size(); i++)
	// 	for (int j = 0; j < i; j++)
	// 		ans += ((abs(S[i] - S[j]) == 1) || (S[i] == 424 && S[j] == 100) || (S[i] == 100 && S[j] == 424));
	// return ans;
	printf("? %lu\n", S.size());
	for (int i = 0; i < (int) S.size(); i++) {
		if (i == 0)
			printf("%d", S[i]);
		else
			printf(" %d", S[i]);
	}
	printf("\n");
	fflush(stdout);
	int ans = 0;
	scanf("%d", &ans);
	return ans;
}


vector <int> UU(vector<int> x, vector <int> y) {
	vector <int> tmp;
	for (auto z: x)
		tmp.push_back(z);
	for (auto z: y)
		tmp.push_back(z);
	return tmp;
}

vector <int> UU(vector<int> x, int y) {
	vector <int> tmp;
	for (auto z: x)
		tmp.push_back(z);
	tmp.push_back(y);
	return tmp;
}

void FindEdge(vector <int> S, int x) {
	if (S.size() == 1) {
		newedgel = S[0];
		e[S[0]][x] = e[x][S[0]] = 1;
	}else {
		vector <int> tmp;
		int l = S.size() / 2;
		for (int i = 0; i < l; i++)
			tmp.push_back(S[i]);
		if (query(UU(tmp, x)) != 0)
			FindEdge(tmp, x);
		else {
			tmp.clear();
			for (int i = l; i < (int) S.size(); i++)
				tmp.push_back(S[i]);
			FindEdge(tmp, x);
		}
	}
}

vector <int> ans;
int dist[700][700];

void dfs_out(int x, int y) {
	if (e[x][y])
		return ;
	for (int k = 1; k <= n; k++)
		if (k != x && k != y && dist[x][k] + dist[k][y] == dist[x][y]) {
			dfs_out(x, k);
			ans.push_back(k);
			dfs_out(k, y);
			return ;
		}
}

void ooo(int x) {
	FindEdge(S2, x);
	int y = newedgel;
	e[x][y] = e[y][x] = 0;
	printf("N ");

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				if (e[i][j])
					dist[i][j] = 1;
				else
					dist[i][j] = 100000000;
		}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	assert(dist[x][y] <= n);

	ans.push_back(x);
	dfs_out(x, y);
	ans.push_back(y);
	// Find path from x to ys
	printf("%lu\n", ans.size());
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i == 0)
			printf("%d", ans[i]);
		else
			printf(" %d", ans[i]);
	}
	printf("\n");
	fflush(stdout);
	exit(0);
}

void search(int l, int r, int nE) {

	if (l == r) {
		assert (nE > 0);
		FindEdge(S1, a[l]);
		if (query(UU(S2, a[l])) != 0) {
			ooo(a[l]);
		}else {
			S2.push_back(a[l]);
		}
	} else {
		vector <int> S;
		for (int i = l; i <= (l + r) / 2; i++)
			S.push_back(a[i]);
		int x = query(UU(S1, S)) - query(S);
		if (x > 0)
			search(l, (l + r) / 2, x);
		if (x < nE)
			search((l + r) / 2 + 1, r, nE - x);
	}
}

void doit() {
	for (int i = 1; i <= n; i++)
		used[i] = false;
	for (auto x : S1)
		used[x] = true;
	for (auto x : S2)
		used[x] = true;
	len = 0;

	vector <int> S;
	for (int i = 1; i <= n; i++)
		if (!used[i])
			a[++len] = i,
			S.push_back(i);

	search(1, len, query(UU(S1, S)) - query(S));

}

int main() {
	scanf("%d", &n);
	S1.push_back(1);
	while (S1.size() + S2.size() < n) {
		doit();
		swap(S1, S2);
	}
	printf("Y\n");
	printf("%lu\n", S1.size());
	for (int i = 0; i < (int) S1.size(); i++) {
		if (i == 0)
			printf("%d", S1[i]);
		else
			printf(" %d", S1[i]);
	}
	printf("\n");
	fflush(stdout);
	// printf("%d\n", cost);
}