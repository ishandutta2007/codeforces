#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 505;
vector<int> sets[N];
int mark[N];
char map[N][N];

bool bySize(int i, int j) {
	return sets[i].size() > sets[j].size();
}

int findGood(vector<vector<int> > &cur, vector<int> &row) {
	for (int i = 0; i < (int)cur.size(); ++i) {
		for (int j = 0; j < (int)cur[i].size(); ++j) {
			mark[cur[i][j]] = i;
		}
	}
	for (int i = 0; i < (int)row.size(); ++i) {
		int u = row[i];
		for (int j = 1; j < (int)sets[u].size(); ++j) {
			if (mark[sets[u][j]] != mark[sets[u][j - 1]]) {
				return u;
			}
		}
	}
	return -1;
}

bool solve(vector<int> &col, vector<int> &row, vector<int> &ret) {
	if (row.size() == 0) {
		ret = col;
		return true;
	}
	sort(row.begin(), row.end(), bySize);
	vector<vector<int> > cur;
	vector<int> one, zero, cut;
	int p;
	p = row.front();
	row.erase(row.begin());
	cut.push_back(p);
	for (int i = 0; i < col.size(); ++i) {
		int u = col[i];
		if (map[p][u] - '0') {
			one.push_back(u);
		} else {
			zero.push_back(u);
		}
	}
	if (!one.size() || !zero.size()) {
		return solve(col, row, ret);
	}
	cur.push_back(one);
	cur.push_back(zero);
	if (row.size() == 0) {
		ret.clear();
		for (int i = 0; i < (int)cur.size(); ++i) {
			for (int j = 0; j < (int)cur[i].size(); ++j) {
				ret.push_back(cur[i][j]);
			}
		}
		return true;	
	}
	bool special = true;
	while ((p = findGood(cur, row)) != -1) {
		for (int i = 0; i < (int)row.size(); ++i) {
			if (row[i] == p) {
				row.erase(row.begin() + i);
				break;
			}
		}
		cut.push_back(p);
		int state = 0;
		bool fail = false;
		vector<vector<int> > rem;
		for (int i = 0; i < (int)cur.size(); ++i) {
			vector<int> tmp = cur[i], one, zero;	
			for (int j = 0; j < (int)tmp.size(); ++j) {
				if (map[p][tmp[j]] - '0') {
					one.push_back(tmp[j]);
				} else {
					zero.push_back(tmp[j]);
				}
			}
			if (state == 0) {
				if (zero.size()) {
					rem.push_back(zero);
				}
				if (one.size()) {
					rem.push_back(one);
					state = 1;
				}
			} else if (state == 1) {
				if (one.size()) {
					rem.push_back(one);
				}
				if (zero.size()) {
					rem.push_back(zero);
					state = 2;
				}
			} else {
				if (zero.size()) {
					rem.push_back(zero);
				}
				if (one.size()) {
					if (i != (int)cur.size() - 1 || !special) {
						return false;
					} else {
						fail = true;
					}
				}
			}
		}
		if (fail) {
			fail = false;
			rem.clear();
			state = 0;
			for (int i = 0; i < (int)cur.size(); ++i) {
				vector<int> tmp = cur[i], one, zero;	
				for (int j = 0; j < (int)tmp.size(); ++j) {
					if (map[p][tmp[j]] - '0') {
						one.push_back(tmp[j]);
					} else {
						zero.push_back(tmp[j]);
					}
				}
				if (i == (int)cur.size() - 1) {
					if (one.size()) {
						rem.insert(rem.begin(), one);
					}
					if (zero.size()) {
						rem.push_back(zero);
					}
					continue;
				}
				if (one.size()) {
					rem.push_back(one);
					if (state == 0) {
						state = 1;
					} else if (state == 2) {
						return false;
					}
				}
				if (zero.size()) {
					rem.push_back(zero);
					if (state == 0) {
						return false;
					} else if (state == 1) {
						state = 2;
					}
				}
			}
		}
		cur = rem;
		special = true;
		int col1 = cur.back().front(), col2 = cur[cur.size() - 1].back();
		for (int i = 0; i < cut.size() && special; ++i) {
			int u = cut[i];
			if (map[u][col1] == '1' && map[u][col2] == '1') {
				special = false;
			}
		}
	}
	vector<vector<int> > cur_row;
	vector<int> empty;
	for (int i = 0; i < (int)cur.size(); ++i) {
		cur_row.push_back(empty);
	}
	for (int i = 0; i < (int)row.size(); ++i) {
		int u = row[i];
		if (sets[u].size() == 0) {
			continue;
		}
		cur_row[mark[sets[u].front()]].push_back(u);
	}
	ret.clear();
	vector<int> tmp;
	for (int i = 0; i < (int)cur.size(); ++i) {
		if (solve(cur[i], cur_row[i], tmp)) {
			for (int j = 0; j < (int)tmp.size(); ++j) {
				ret.push_back(tmp[j]);
			}
			tmp.clear();
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	vector<int> col, row, ret;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
		for (int j = 0; j < n; ++j) {
			if (map[i][j] - '0') {
				sets[i].push_back(j);
			}
		}
		col.push_back(i);
		row.push_back(i);
	}
	if (solve(col, row, ret)) {
		puts("YES");
		char ans[N];
		ans[n] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ans[j] = map[i][ret[j]];
			}
			printf("%s\n", ans);
		}
	} else {
		puts("NO");
	}
	return 0;
}