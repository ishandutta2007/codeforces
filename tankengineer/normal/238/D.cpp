#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

const int N = 100005;
int n, q, next[N], fore[N], cnt, appear[N], leftleave[N];
char p[N];
vector<int> pos;
vector<vector<int> > sum;

const int RIGHT = 0, LEFT = 1;

void run() {
	int cr = 0, dr = RIGHT, lcr;
	bool dir = false;
	vector<int> tsum = sum.back();
	do {
		lcr = cr;
		if (dr == RIGHT) {
			cr = next[cr];
		} else {
			cr = fore[cr];
		}
		if (cr > 0 && cr <= n) {
			if (p[cr] >= '0' && p[cr] <= '9') {
				++tsum[p[cr] - '0'];
				if (p[cr] == '0') {
					next[fore[cr]] = next[cr];
					fore[next[cr]] = fore[cr];
					--cnt;
				} else {
					--p[cr];
				}
				dir = false;
			} else {
				if (p[cr] == '>') {
					dr = RIGHT;
				} else {
					dr = LEFT;
				}
				if (dir) {
					next[fore[lcr]] = next[lcr];
					fore[next[lcr]] = fore[lcr];
					--cnt;
				}
				dir = true;
			}
		}
		sum.push_back(tsum);
		pos.push_back(cr);
	} while (cr > 0 && cr <= n);
	if (cnt == 1 && p[next[0]] == '>' || p[next[0]] == '<') {
		int i = next[0];
		next[fore[i]] = next[i];
		fore[next[i]] = fore[i];
		--cnt;
	}
}

int main() {
	scanf("%d%d%s", &n, &q, p + 1);
	for (int i = 0; i <= n; ++i) {
		next[i] = i + 1;
		fore[i] = i - 1;
	}
	vector<int> tmp;
	for (int i = 0; i < 10; ++i) {
		tmp.push_back(0);
	}
	sum.push_back(tmp);
	cnt = n;
	while (cnt) {
		run();
	}

	int INF = sum.size() - 1;
	set<int> uncal;
	for (int i = 0; i <= n + 1; ++i) {
		appear[i] = INF;
		leftleave[i] = INF;
		uncal.insert(i);
	}
	for (int i = 0; i < (int)pos.size(); ++i) {
		int u = pos[i];
		if (appear[u] == INF) {
			appear[u] = i;
		}
		if (i > 0 && u < pos[i - 1]) {
			set<int>::iterator lb = uncal.upper_bound(pos[i]),
							   rb = uncal.upper_bound(pos[i - 1]);
			for (set<int> :: iterator it = lb; it != rb; ++it) {
				leftleave[*it] = i;
			}
			uncal.erase(lb, rb);
		}
	}
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int pl = appear[l], pr = min(appear[r + 1], leftleave[l]);
		for (int j = 0; j < 10; ++j) {
			printf("%d%c", sum[pr][j] - sum[pl][j], j == 9 ? '\n' : ' ');
		}
	}
	return 0;
}