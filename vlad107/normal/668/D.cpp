#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>
 
using namespace std;

const int N = 1e6 + 100;

struct Quest {
	int tp, t, x;
	Quest() {}
	void read() {
		scanf("%d%d%d", &tp, &t, &x);
	}
};

int vals[N], cv, n;
Quest quest[N];
vector<int> moments[N], sa[N];

void mod(int x, int y, int val) {
	for (int i = y + 1; i < (int)sa[x].size(); i = (i | (i - 1)) + 1) {
		sa[x][i] += val;
	}
}

int getsum(int x, int y) {
	int res = 0;
	for (int i = y + 1; i > 0; i &= (i - 1)) {
		res += sa[x][i];
	}
	return res;
}

int main() {
//	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		quest[i].read();
		vals[cv++] = quest[i].x;
	}
	sort(vals, vals + cv);
	cv = unique(vals, vals + cv) - vals;
	for (int i = 0; i < n; i++) {
		quest[i].x = lower_bound(vals, vals + cv, quest[i].x) - vals;
		moments[quest[i].x].push_back(quest[i].t);
	}
	for (int i = 0; i < cv; i++) {
		sort(moments[i].begin(), moments[i].end());
		moments[i].resize(unique(moments[i].begin(), moments[i].end()) - moments[i].begin());
		sa[i].resize(moments[i].size() + 2);
	}
	for (int i = 0; i < n; i++) {
		int tt = quest[i].t;
		int xx = quest[i].x;
		tt = lower_bound(moments[xx].begin(), moments[xx].end(), tt) - moments[xx].begin();
		if (quest[i].tp == 1) {
			mod(xx, tt, +1);
		} else if (quest[i].tp == 2) {
			mod(xx, tt, -1);
		} else if (quest[i].tp == 3) {
			printf("%d\n", getsum(xx, tt));
		} else assert(false);
	}
}