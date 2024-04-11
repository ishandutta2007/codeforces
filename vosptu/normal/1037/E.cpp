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

#define N 410000
int n, m, k, a[N], b[N], deg[N], ans[N];
bool in[N];
set <pair<int, int> > degs;
vector <int> ve[N];

void doit() {
	while (!degs.empty() && degs.begin()->first < k) {
		int x = degs.begin()->second;
		// cout << x << ' ' << deg[x] << endl;
		degs.erase(degs.begin());
		in[x] = false;
		for (int i = 0; i < (int) ve[x].size(); i++)
			if (in[ve[x][i]]) {
				degs.erase(make_pair(deg[ve[x][i]], ve[x][i]));
				deg[ve[x][i]]--;
				degs.insert(make_pair(deg[ve[x][i]], ve[x][i]));
			}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a[i], &b[i]);
		deg[a[i]]++;
		deg[b[i]]++;
		ve[a[i]].push_back(b[i]);
		ve[b[i]].push_back(a[i]);
	}
	for (int i = 1; i <= n; i++)
		in[i] = true;
	for (int i = 1; i <= n; i++)
		degs.insert(make_pair(deg[i], i));
	doit();
	ans[m] = degs.size();
	for (int i = m; i; i--) {
		// printf("bbbbbbbb\n");
		ve[a[i]].pop_back();
		ve[b[i]].pop_back();
		if (in[a[i]] && in[b[i]]) {
			degs.erase(make_pair(deg[a[i]], a[i]));
			deg[a[i]]--;
			degs.insert(make_pair(deg[a[i]], a[i]));

			degs.erase(make_pair(deg[b[i]], b[i]));
			deg[b[i]]--;
			degs.insert(make_pair(deg[b[i]], b[i]));
		}
		doit();
		
		// printf("bbbbbbb\n");
		ans[i - 1] = degs.size();
	}
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
}